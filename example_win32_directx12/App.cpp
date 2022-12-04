#include "App.h"

#include "ImguiDockable.h"
#include "imgui.h"

#include <windows.h>


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
            static float f = 0.0f;
            static int counter = 0;
            static POINT mousePosition;

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
