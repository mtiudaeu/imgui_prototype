#pragma once

#include <windows.h>

namespace Command {
    enum ECommand {
        RECORD,
        PLAY,
        TOGGLE_IMGUI_DEMO
    };

    void AddHotkey(ECommand cmd, size_t hotkey);
    void SeekAndRunCommands();
}
