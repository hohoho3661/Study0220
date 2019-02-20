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
	desc.AppName = L"D3D Game"; // 제목표시줄에 나타날 이름
	desc.Instance = instance; // 프로그램 시작주소, 식별자
	desc.bFullScreen = false; // 전체화면
	desc.bVsync = false; // 수직동기화 (60고정)
	desc.Handle = NULL; // 윈도우생성
	desc.Width = 1280;
	desc.Height = 720;
	desc.Background = D3DXCOLOR(1, 1, 1, 1);
	D3D::SetDesc(desc);


	Main* main = new Main();
	WPARAM wParam = Window::Run(main);

	SAFE_DELETE(main);

	return wParam;
}