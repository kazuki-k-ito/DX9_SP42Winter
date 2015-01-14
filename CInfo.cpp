#include "CInfo.h"
#include "CDirectxGraphics.h"

extern CDirectXGraphics g_DXGrobj;

CInfo::CInfo()
{
	const string fontPath = "resource/font/";			// �t�H���g�֌W�̃t�H���_�p�X
	// �^�C�g�������̏�����
	m_pTitle = std::make_shared<CFont>();
	m_pTitle->Load( ( fontPath + "ASCII.txt" ).c_str() );
	m_pTitle->Load( ( fontPath + "�����f�[�^.txt" ).c_str() );
	m_pTitle->CreateTexture( 32, "���˂���Ղ����", ( fontPath + "cinecaption227.ttf" ).c_str() );
	SetTitle( "SP42�~�G�V�F�[�_�[�ۑ�" );

	// �f�o�C�X���̏�����
	m_pDeviceInfo = std::make_shared<CMenu>();
	m_pDeviceInfo->Load( ( fontPath + "ASCII.txt" ).c_str() );
	m_pDeviceInfo->Load( ( fontPath + "�����f�[�^.txt" ).c_str() );
	m_pDeviceInfo->CreateTexture( 16, "���˂���Ղ����", ( fontPath + "cinecaption227.ttf" ).c_str() );
	m_pDeviceInfo->SetPitch( 0.0f );
	m_pDeviceInfo->SetPosition( 480, 10 );
	SetDeviceInfo();

	// ��������̏�����
	m_pUserGuide = std::make_shared<CMenu>();
	m_pUserGuide->Load( ( fontPath + "ASCII.txt" ).c_str() );
	m_pUserGuide->Load( ( fontPath + "�����f�[�^.txt" ).c_str() );
	m_pUserGuide->CreateTexture( 16, "���˂���Ղ����", ( fontPath + "cinecaption227.ttf" ).c_str() );
	m_pUserGuide->SetPitch( 10.0f );
	m_pUserGuide->SetPosition( 10, 200 );
	SetUserGuide();
}


CInfo::~CInfo()
{

}

//======================================================
// @brief:�^�C�g�������̐ݒ�
//------------------------------------------------------
// @author:K.Ito
// @param:�ݒ肷�镶��
// @return:none
//======================================================
void CInfo::SetTitle(string str)
{
	m_sTitle = str;
}

//======================================================
// @brief:�f�o�C�X���̐ݒ�
//------------------------------------------------------
// @author:K.Ito
// @param:none
// @return:none
//======================================================
void CInfo::SetDeviceInfo()
{
	char buf[256];

	m_pDeviceInfo->PushMenu( "�f�o�C�X���" );
	// �}���`�����_�����O�^�[�Q�b�g�̍ő吔
	D3DCAPS9 Caps;
	g_DXGrobj.GetDXDevice()->GetDeviceCaps( &Caps );
	sprintf_s( buf, "�ő�}���`�����_�����O�^�[�Q�b�g:%d", Caps.NumSimultaneousRTs );
	m_pDeviceInfo->PushMenu( buf );
	sprintf_s( buf, "�ő�e�N�X�`���𑜓x:%d�~%d", Caps.MaxTextureWidth, Caps.MaxTextureHeight );
	m_pDeviceInfo->PushMenu( buf );
	sprintf_s( buf, "�o�b�N�o�b�t�@�T�C�Y:%d�~%d", g_DXGrobj.GetDXD3dpp().BackBufferWidth, g_DXGrobj.GetDXD3dpp().BackBufferHeight );
	m_pDeviceInfo->PushMenu( buf );
	sprintf_s( buf, "���p�\VRAM:%dMB", g_DXGrobj.GetDXDevice()->GetAvailableTextureMem() / 1024 / 1024 );
	m_pDeviceInfo->PushMenu( buf );
	sprintf_s( buf, "HAL:%s", g_DXGrobj.GetDXAdapter().Description );
	m_pDeviceInfo->PushMenu( buf );
}

//======================================================
// @brief:��������̐ݒ�
//------------------------------------------------------
// @author:K.Ito
// @param:none
// @return:none
//======================================================
void CInfo::SetUserGuide()
{
	m_pUserGuide->PushMenu( "������@" );
	m_pUserGuide->PushMenu( "����1" );
	m_pUserGuide->PushMenu( "����2" );
	m_pUserGuide->PushMenu( "����3" );
}

//======================================================
// @brief:�`�悷��
//------------------------------------------------------
// @author:K.Ito
// @param:none
// @return:none
//======================================================
void CInfo::Draw()
{
	m_pTitle->PrintChar( m_sTitle.c_str(), 10, 10, D3DCOLOR_XRGB( 255, 0, 255 ) );
	m_pDeviceInfo->Draw();
	m_pUserGuide->Draw();
}