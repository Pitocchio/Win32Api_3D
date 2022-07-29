#pragma once
#include "cMatrix.h"
#include "cVector3.h"
#include "framework.h"

class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private:
	HDC			m_MemDC;
	HBITMAP		m_hOldBtimap,m_hBitmap;

	std::vector<cVector3>	 m_vecVertex;
	std::vector<DWORD>		 m_vecIndex;

	cMatrix			m_matWorld; //���� ��Ʈ���� (������ǥ��)
	cMatrix			m_matView; //�� ��Ʈ���� (ī�޶�=�� �� ���� �ʿ��� ���Ʈ����)
	cMatrix			m_matProj; // �������� ��Ʈ���� (���ٰ��� �ִ� )
	cMatrix			m_matViewport; //�� ��Ʈ ��Ʈ���� (��ǻ�Ͱ� ȭ�鿡 �׸��� �׷��� �� �ʿ��� ���Ʈ����)

	cVector3		m_vEye; // position ���� ������ = �� ��ġ
	cVector3		m_vLookAt; // ���� ���°��� position
	cVector3		m_vUp; // ������ ���⺤��

	cVector3		m_vPosition;
	float			m_fBoxRotY; //��ü�� y��������� ȸ���� ���(ANGLE)
	cVector3		m_vBoxDirection; //��ü�� ����

	//�ٴڿ� �����Ѱ�
	std::vector<cVector3>	m_vecLineVertex;
	cVector3				m_vAxisXTextPosition;
	cVector3				m_vAxisZTextPosition;

	POINT				m_ptPrevMouse;
	bool				m_isLButtonDown;
	float				m_fCameraDistance;
	cVector3			m_vCamRotAngle;

	float				m_fScale;

public:
	void Setup();
	void Update();
	void Render(HDC hdc);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	//
	void SetGrid();
	void DrawGrid();
	bool IsBackFace(cVector3& v1, cVector3& v2, cVector3& v3); // �����̽� �ø�
	void Update_Rotation();
	void Update_Move();
	void Update_Scale();
};

