#include <Windows.h>
#include <cstdio>

#include <memory>
#include <vector>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Core/Image.h"
#include "Core/Camera.h"
#include "Core/Application.h"

class MyImGuiLayer : public ImGuiLayer
{
public:
	MyImGuiLayer()
		:m_Camera(45.0f, 0.1f, 100.0f)
	{
		//m_Renderer = std::make_shared<PathTracing>();
		//m_SceneNames.push_back("Importance_Sampling");
		//createScenePtrs.push_back(ImportanceSampling);
	}

	virtual void OnUpdate(float ts) override
	{
		int width, height;
		auto window = Application::Get().GetGLFWwindow();
		//glfwGetWindowSize(window, &width, &height);
		glfwGetFramebufferSize(window, &width, &height);
		m_Width = width; m_Height = height;

		glViewport(0, 0, m_Width, m_Height);

		m_Camera.OnUpdate(ts);
		//m_Renderer->OnResize(m_Width, m_Height);
	}

	virtual void ShowUI(float ts) override
	{
		ImGui::Begin("Setting");

		ImGui::Text("The average fps: %.3f", ImGui::GetIO().Framerate);

		//ImGui::Combo("Scene", &m_SceneIndex, m_SceneNames.data(), m_SceneNames.size());
		ImGui::Separator();
		ImGui::DragFloat3("Camera Position", glm::value_ptr(m_Camera.GetPosition()));
		ImGui::DragFloat3("Camera Direction", glm::value_ptr(m_Camera.GetDirection()));
		ImGui::Checkbox("Camera Rotation", &m_Camera.GetIsRotation());

		ImGui::End();
	}

	virtual void Render(float ts) override
	{
		//if (m_CurrentIndex != m_SceneIndex)
		//{
		//	m_CurrentIndex = m_SceneIndex;
		//	m_Scene = createScenePtrs[m_CurrentIndex]();
		//	//m_Renderer->isNewScene = true;
		//}
		//m_Renderer->Render(m_Camera, m_Scene);
		//m_Renderer->isNewScene = false;
	}

private:
	unsigned int m_Width = 0, m_Height = 0;

	//std::shared_ptr<PathTracing> m_Renderer;
	//Scene m_Scene;
	//std::vector<const char*> m_SceneNames;
	//std::vector<Scene(*)()> createScenePtrs;

	int m_SceneIndex = 0;
	int m_CurrentIndex = -1;
	Camera m_Camera;
};


int main()
{
	static Application* RayTracing = new Application("PathTracing");
	std::shared_ptr<MyImGuiLayer> myimguilayer = std::make_shared<MyImGuiLayer>();

	RayTracing->PushImGuiLayer(myimguilayer);
	RayTracing->Run();

	return 0;
}