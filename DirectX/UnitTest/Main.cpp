#include "stdafx.h"
#include "Main.h"
#include "Systems/Window.h"
#include "DrawVertex.h"

void Main::Initialize()
{
	Push(new DrawVertex());
}

void Main::Ready()
{
}

void Main::Destroy()
{
	for (IExecute* exe : executes)
	{
		exe->Destroy();
		SAFE_DELETE(exe);
	}
}

void Main::Update()
{
	for (IExecute* exe : executes)
		exe->Update();
}

void Main::PreRender()
{
	for (IExecute* exe : executes)
		exe->PreRender();
}

void Main::Render()
{
	for (IExecute* exe : executes)
		exe->Render();
}

void Main::PostRender()
{
	for (IExecute* exe : executes)
		exe->PostRender();
}

void Main::ResizeScreen()
{
	for (IExecute* exe : executes)
		exe->ResizeScreen();
}

void Main::Push(IExecute * execute)
{
	executes.push_back(execute);

	execute->Initialize();
}


int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR param, int command)
{
	D3DDesc desc;
	desc.AppName = L"D3D Game"; // ����ǥ���ٿ� ��Ÿ�� �̸�
	desc.Instance = instance; // ���α׷� �����ּ�, �ĺ���
	desc.bFullScreen = false; // ��üȭ��
	desc.bVsync = false; // ��������ȭ (60����)
	desc.Handle = NULL; // ���������
	desc.Width = 1280;
	desc.Height = 720;
	desc.Background = D3DXCOLOR(1, 1, 1, 1);
	D3D::SetDesc(desc);


	Main* main = new Main();
	WPARAM wParam = Window::Run(main);

	SAFE_DELETE(main);

	return wParam;
}