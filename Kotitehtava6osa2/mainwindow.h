#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString number1, number2;           // QString is handy as it can be printed easily to QLineEdit
    int state;                          // state variable is needed to know which number is being given
    float result;                       // result is calculated when user pressed enter
    short operand;                      // operand is stored when user presses + or - or * or / buttons

    void numberClickedHandler();        // This function is called from all number QPushButton click handlers
    void clearAndEnterClickHandler();   // This handles clear and enter buttons
    void addSubMulDivClickHandler();    // And one handler for +,-,*,/ buttons also
    void resetLineEdits();              // This is handy for resetting all 3 QlineEdits
};
#endif // MAINWINDOW_H
