#pragma once


// CWmaEncodeCfgDlg 对话框

class CWmaEncodeCfgDlg : public CDialog
{
	DECLARE_DYNAMIC(CWmaEncodeCfgDlg)

public:
	CWmaEncodeCfgDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CWmaEncodeCfgDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WMA_ENCODE_CFG_DIALOG };
#endif

	int m_bitrate;

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_bitrate_combo;
	afx_msg void OnCbnSelchangeBitrateCombo();
};
