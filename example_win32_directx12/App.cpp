#include "App.h"

#include "ImguiDockable.h"
#include "imgui.h"

#include "Commands.h"

#include <windows.h>

#include <thread>


namespace{
    bool show_demo_window = false;
}

namespace App {
    
    void Init() {
        Command::AddHotkey(Command::ECommand::TOGGLE_IMGUI_DEMO, VK_F2);
    }

    void RenderUI() {
        // ---------- Update ----------
        Command::SeekAndRunCommands();

        // ---------- Render ----------
        ImguiShowDockSpace();

        if (show_demo_window)
            ImGui::ShowDemoWindow(nullptr);

        ImGui::Begin("App");
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Text("This is some useful text.");
            ImGui::Checkbox("Demo Window", &show_demo_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);

            if (ImGui::Button("Button"))
                counter++;

            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

            if (ImGui::Button("Move mouse")) {
                SetCursorPos(100, 100);
            }

            static POINT mousePosition;
            GetCursorPos(&mousePosition);
            ImGui::Text("Cursor Position : x : %d, y : %d", mousePosition.x, mousePosition.y);
        }
        ImGui::End();

    }
    
    void ToggleShowDemoWindow() {
        show_demo_window = !show_demo_window;
    }
}
