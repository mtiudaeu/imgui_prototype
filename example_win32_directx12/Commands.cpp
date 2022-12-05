#include "Commands.h"

#include <map>
#include <vector>

namespace {
    std::map<Command::ECommand, std::vector<size_t>> m_HotkeysByCommands;
}

namespace Command {
    void AddHotkey(ECommand cmd, size_t hotkey) {
        //Improvement : Check for duplication hotkeys.
        //              Could maintain a set of hotkeys to check if already present. Or map pointing to the command for better logs.

        auto& hotkeys = m_HotkeysByCommands[cmd];
        hotkeys.push_back(hotkey);
    }

    void SeekAndRunCommands() {
        //mdtmp 
    }
}
