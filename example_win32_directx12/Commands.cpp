#include "Commands.h"

#include "App.h"

#include <map>
#include <vector>
#include <thread>

namespace {
    std::map<Command::ECommand, std::vector<size_t>> m_HotkeysByCommands;

    void ExecuteCommand(Command::ECommand cmd) {
        switch (cmd) {
        case Command::TOGGLE_IMGUI_DEMO:
            App::ToggleShowDemoWindow();
            break;
        }
    }
}

namespace Command {
    void AddHotkey(ECommand cmd, size_t hotkey) {
        //Improvement : Check for duplication hotkeys.
        //              Could maintain a set of hotkeys to check if already present. Or map pointing to the command for better logs.

        auto& hotkeysByCommand = m_HotkeysByCommands[cmd];
        hotkeysByCommand.push_back(hotkey);
    }

    void SeekAndRunCommands() {
        for (const auto& hotkeysByCommand : m_HotkeysByCommands) {
            const auto command = hotkeysByCommand.first;
            const auto& hotkeys = hotkeysByCommand.second;
            for (auto hotkey : hotkeys) {
                if (GetAsyncKeyState(hotkey)) {
                    ExecuteCommand(command);
                }
            }
        }
        
        //mdtmp Move to Commands.cpp
        //      and call Command::AddHotkey from here.
        /*
        if (GetAsyncKeyState(VK_F2)) {
            App::ToggleShowDemoWindow();

            INPUT in[4] = {};
            ZeroMemory(in, sizeof(in));

            in[0].type = INPUT_KEYBOARD;
            in[0].ki.wVk = 0x44;
            in[0].ki.dwFlags = KEYEVENTF_EXTENDEDKEY;

            in[1].type = INPUT_KEYBOARD;
            in[1].ki.wVk = 0x44;
            in[1].ki.dwFlags = KEYEVENTF_KEYUP;

            UINT uS = SendInput(2, in, sizeof(INPUT));

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        */
    }
}
