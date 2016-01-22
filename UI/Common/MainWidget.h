#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <qlabel.h>
#include "AppBase.h"
#include "Button.h"
#include "AppListWidget.h"
#include "CustomCombobox.h"

#include "Show/Show.h"

typedef struct CommandInformation
{
    std::string strCmd;
    int iParentId;
    // 如果是Menu则是MenuID，如果是Command则是CommandID
    int iId;
    bool bMenu;
    std::vector<CommandInformation> CmdVec;
}tagCmdInf;

class MainWidget : public BaseWidght
{
    Q_OBJECT
public:
    explicit MainWidget(AppListInterface * pList, QWidget *parent = 0);
    ~MainWidget();

protected:
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void showEvent(QShowEvent * e);
signals:
    void ExitApp();
    void CommandClick(int iCmdId);
public slots:
    // 列表框点击响应槽
    void OnCommandListItemClicked(QListWidgetItem *pItem);
    // 菜单点击相应槽
    void BtnMenuClickedSlots();
    // 软按键点击相应槽
    void SoftBtnClickedSlot(int iSoftBtnID);
private:
    void setSoftButtons(std::vector<SSoftButton> vec_softButtons);

    void AddCommand(int iCmdId,std::string strName);
    void AddMenu(int iMenuId,std::string strName);
    void AddSubCommand(int iParentId,int iCmdId,std::string strName);
    // 如果pMenu为nullptr表示主菜单
    void RefreshCommandList(tagCmdInf *pMenu);
    // 隐藏command列表
    void HideCommandList();

    std::vector<tagCmdInf> m_CmdVec;

    QLabel *m_pAppNameLab;
    QLabel *m_pMainTitleLab;
    QLabel *m_pIconLab;
    CButton *m_pMenuBtn;
    // 三个软按键
    CButton *m_pSoftBtn;

    AppListInterface *m_pList;

    CustomCombobox *m_pCommandList;
    // 如果为主菜单则为nullptr，子菜单则是该子菜单的结构体指针
    tagCmdInf *m_pCurrentMenu;
};

#endif // MAINWIDGET_H
