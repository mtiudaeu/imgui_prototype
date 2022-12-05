#include "App.h"

#include "ImguiDockable.h"
#include "imgui.h"

#include <windows.h>

#include <thread>


namespace{
    bool show_demo_window = false;
}

namespace App {
    

    void RenderUI() {
        ImguiShowDockSpace();

        if (show_demo_window)
            ImGui::ShowDemoWindow(nullptr);


        ImGui::Begin("App");
        {
            //---------
            static float f = 0.0f;
            static int counter = 0;
            static POINT mousePosition;

            //mdtmp Move to Commands.cpp
            //      and call Command::AddHotkey from here.
            if (GetAsyncKeyState(VK_F2)) {
                show_demo_window = !show_demo_window;

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

            GetCursorPos(&mousePosition);


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
            ImGui::Text("Cursor Position : x : %d, y : %d", mousePosition.x, mousePosition.y);
        }
        ImGui::End();

    }
}
