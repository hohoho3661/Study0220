#include "stdafx.h"
#include "DrawVertex.h"

void DrawVertex::Initialize()
{
	shader = new Shader(L"001_Vertex.fx");

	vertices[0].Position = D3DXVECTOR3(0, 0, 0);
	vertices[1].Position = D3DXVECTOR3(0, 1, 0);
	vertices[2].Position = D3DXVECTOR3(1, 0, 0);

	D3D11_BUFFER_DESC desc = { 0 };
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.ByteWidth = sizeof(Vertex) * 3;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA data = { 0 };
	data.pSysMem = vertices;

	HRESULT hr = D3D::GetDevice()->CreateBuffer(&desc, &data, &vertexBuffer);
	assert(SUCCEEDED(hr));


}

void DrawVertex::Ready()
{
}

void DrawVertex::Destroy()
{
	SAFE_DELETE(shader);
	SAFE_RELEASE(vertexBuffer);
}

void DrawVertex::Update()
{
}

void DrawVertex::PreRender()
{
}

void DrawVertex::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	shader->Draw(0, 0, 3);
}

void DrawVertex::PostRender()
{
}

void DrawVertex::ResizeScreen()
{
}
