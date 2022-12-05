#pragma once

#include <windows.h>

namespace Command {
    enum ECommand {
        RECORD,
        PLAY
    };

    void AddHotkey(ECommand cmd, size_t hotkey);
    void SeekAndRunCommands();
}
