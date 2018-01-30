#pragma once

#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace engine 
{ 
	namespace graphics 
	{
		class Window
		{
		private:
			const char *m_Name;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;
			bool m_Keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			double mx, my;
		public:
			Window(const char *name, int width, int height);
			~Window();
			void update();
			bool closed() const;
			void clear() const;


			inline int GetWidth() const{ return m_Width; }
			inline int GetHeight() const{ return m_Height; }

			// input 
			bool isKeyPressed(unsigned int key) const;
			bool isMouseButtonPressed(unsigned int button) const;
			void getMousePosition(double &x, double &y) const;
		
		private:
			bool init();

			// callback functions todo:: see it again !!
			friend void window_resize(GLFWwindow *window, int width, int height);
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};

	}
}

