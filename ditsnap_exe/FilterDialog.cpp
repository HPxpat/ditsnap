
#include "FilterDialog.h"
#include "resource.h"

FilterDialog::FilterDialog(TableListView& mainListView) : mainListView_(mainListView) {};

BOOL FilterDialog::OnInitDialog(CWindow wndFocus, LPARAM lInitParam) {
	CenterWindow();
	auto hIcon = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR,
	                                           GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON));
	SetIcon(hIcon, TRUE);
	HICON__* hIconSmall = AtlLoadIconImage(IDR_MAINFRAME, LR_DEFAULTCOLOR,
	                                                    GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON));
	SetIcon(hIconSmall, FALSE);
	checkBoxClassSchema_ = GetDlgItem(IDC_CHECK1);
	checkBoxAttributeSchema_ = GetDlgItem(IDC_CHECK2);
	checkBoxSubSchema_ = GetDlgItem(IDC_CHECK3);
	checkBoxDisplaySpecifier_ = GetDlgItem(IDC_CHECK4);
	checkBoxOthers_ = GetDlgItem(IDC_CHECK5);
	checkBoxClassSchema_.SetCheck(BST_CHECKED);
	checkBoxAttributeSchema_.SetCheck(BST_CHECKED);
	checkBoxSubSchema_.SetCheck(BST_CHECKED);
	checkBoxDisplaySpecifier_.SetCheck(BST_CHECKED);
	checkBoxOthers_.SetCheck(BST_CHECKED);
	return TRUE;
}

void FilterDialog::OnOK(UINT uNotifyCode, int nID, CWindow wndCtl) {
	int filterFlag = checkBoxClassSchema_.GetCheck();
	filterFlag += checkBoxAttributeSchema_.GetCheck() << 1;
	filterFlag += checkBoxSubSchema_.GetCheck() << 2;
	filterFlag += checkBoxDisplaySpecifier_.GetCheck() << 3;
	filterFlag += checkBoxOthers_.GetCheck() << 4;
	mainListView_.FilterTable(filterFlag);
	EndDialog(nID);
}

void FilterDialog::OnCancel(UINT uNotifyCode, int nID, CWindow wndCtl) {
	EndDialog(nID);
}
