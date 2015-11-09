#ifndef CCHOICESETVR_H
#define CCHOICESETVR_H

#include "UI/Common/PopBase.h"
#include "QLabel"
#include "UI/Common/Button.h"

#define PERFORMINTERACTION_TIMEOUT      10
#define PERFORMINTERACTION_CHOICE       0

class CChoicesetVR : public CPopBase
{
    Q_OBJECT
public:
    explicit CChoicesetVR(CPopBase *parent = 0);
    ~CChoicesetVR();

    void execShow(AppDataInterface* pAppInterface);
    void testShow();

signals:
    void VRmenuClicked(int code, int id, int choiceID);

public slots:
    void timeoutSlots();
    void label1ClickedSlots(int id);
    void label2ClickedSlots(int id);
    void label3ClickedSlots(int id);
    void label4ClickedSlots(int id);

private:
    void setChoicesetVRText(int textIdx, QString text);
    void setChoicesetVRID(int btnIdx, int id);
    void setTimeOut(int duration);
    void setInteractionID(int id);

private:
    QLabel *m_labelVRIcon;
    QLabel *m_labelText;
    CButton *m_labelSet1;
    CButton *m_labelSet2;
    CButton *m_labelSet3;
    CButton *m_labelSet4;

    int m_i_interactionID;
    int m_i_defaultID;

    void InitLayout();
};

#endif // CCHOICESETVR_H
