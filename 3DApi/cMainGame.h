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

	cMatrix			m_matWorld; //월드 매트릭스 (절대좌표계)
	cMatrix			m_matView; //뷰 매트릭스 (카메라=눈 이 볼때 필요한 뷰매트릭스)
	cMatrix			m_matProj; // 프로젝션 매트릭스 (원근감을 주는 )
	cMatrix			m_matViewport; //뷰 포트 매트릭스 (컴퓨터가 화면에 그림을 그려줄 때 필요한 뷰매트릭스)

	cVector3		m_vEye; // position 눈의 포지션 = 내 위치
	cVector3		m_vLookAt; // 내가 보는곳의 position
	cVector3		m_vUp; // 정수리 방향벡터

	cVector3		m_vPosition;
	float			m_fBoxRotY; //물체의 y축기준으로 회전시 사용(ANGLE)
	cVector3		m_vBoxDirection; //물체의 전방

	//바닥에 관련한것
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
	bool IsBackFace(cVector3& v1, cVector3& v2, cVector3& v3); // 백페이스 컬링
	void Update_Rotation();
	void Update_Move();
	void Update_Scale();
};

