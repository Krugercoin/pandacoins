#ifndef MININGPAGE_H
#define MININGPAGE_H

#include "bitcoingui.h"
#include <QtWidgets/QDialog>

namespace Ui {
class MiningPage;
}
class ClientModel;
class MiningPage : public QDialog
{
    Q_OBJECT
    
public:
    explicit MiningPage(QWidget *parent = 0);
    ~MiningPage();

    enum MessageClass {
        MC_ERROR,
        MC_DEBUG,
        CMD_REQUEST,
        CMD_REPLY,
        CMD_ERROR
    };

    void SetMiningStatus(bool isMining);
    bool SetGenerate(bool start, int proc);
    
public slots:
    void clear();
    void message(int category, const QString &message, bool html = false);
    void scrollToEnd();
    void slotUpdateSpeed();

private slots:
    void on_bStartMining_clicked();

    void on_bStopMining_clicked();

private:
    //int timer_id;
    Ui::MiningPage *ui;
    BitcoinGUI *_mainFrom;    

//protected:
    //virtual void timerEvent( QTimerEvent* );

};

#endif // MININGPAGE_H
