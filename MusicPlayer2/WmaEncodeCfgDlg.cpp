// CWmaEncodeCfgDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MusicPlayer2.h"
#include "WmaEncodeCfgDlg.h"
#include "afxdialogex.h"


// CWmaEncodeCfgDlg 对话框

IMPLEMENT_DYNAMIC(CWmaEncodeCfgDlg, CDialog)

CWmaEncodeCfgDlg::CWmaEncodeCfgDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_WMA_ENCODE_CFG_DIALOG, pParent)
{

}

CWmaEncodeCfgDlg::~CWmaEncodeCfgDlg()
{
}

void CWmaEncodeCfgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BITRATE_COMBO, m_bitrate_combo);
}


BEGIN_MESSAGE_MAP(CWmaEncodeCfgDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_BITRATE_COMBO, &CWmaEncodeCfgDlg::OnCbnSelchangeBitrateCombo)
END_MESSAGE_MAP()


// CWmaEncodeCfgDlg 消息处理程序


BOOL CWmaEncodeCfgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_bitrate_combo.AddString(_T("16"));
	m_bitrate_combo.AddString(_T("24"));
	m_bitrate_combo.AddString(_T("32"));
	m_bitrate_combo.AddString(_T("48"));
	m_bitrate_combo.AddString(_T("64"));
	m_bitrate_combo.AddString(_T("80"));
	m_bitrate_combo.AddString(_T("96"));
	m_bitrate_combo.AddString(_T("128"));
	m_bitrate_combo.AddString(_T("160"));
	m_bitrate_combo.AddString(_T("192"));
	m_bitrate_combo.AddString(_T("224"));
	m_bitrate_combo.AddString(_T("256"));
	m_bitrate_combo.AddString(_T("320"));

	CString bitrate;
	bitrate.Format(_T("%d"), m_bitrate);
	int index;
	index = m_bitrate_combo.FindStringExact(0, bitrate);
	m_bitrate_combo.SetCurSel(index);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CWmaEncodeCfgDlg::OnCbnSelchangeBitrateCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_bitrate_combo.GetLBText(m_bitrate_combo.GetCurSel(), str);
	m_bitrate = _ttoi(str);
}
