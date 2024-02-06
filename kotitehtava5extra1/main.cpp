#include <iostream>
#include <string>

using namespace std;

class DeviceBaseClass {
protected:
    short deviceID;
public:
    //deviceID:n arvo 0 aluksi
    DeviceBaseClass(): deviceID(0){}
     void setDeviceID(){
        cout << "Enter device ID: ";
        cin >> deviceID;
    }

    short getDeviceID(){
        return deviceID;
    }
};

class DeviceMouse : public DeviceBaseClass {
private:
    short primaryButton;
public:
    //primaryButton arvo 0 aluksi
    DeviceMouse(): primaryButton(0){}
    void setPrimaryButton() {
        cout << "Set Mouse Primary Button(1-2): ";
        cin >> primaryButton;
        //Ehtolause käyttäjän syötteelle
        while (primaryButton < 1 || primaryButton > 2) {
            cout << "Invalid input. Please enter a value between 1 and 2: ";
            cin >> primaryButton;
        }
    }

    short getPrimaryButton(){
        return primaryButton;
    }
};

class DeviceDisplay : public DeviceBaseClass {
private:
    short displayResolution;
public:
    //displayResolution arvo 0 aluksi
    DeviceDisplay(): displayResolution(0){}
    void setDisplayResolution() {
        cout << "Enter display resolution (1-10): ";
        cin >> displayResolution;
        //Ehtolause käyttäjän syötteelle
        while (displayResolution < 1 || displayResolution > 10 ) {
            cout << "Invalid input. Please enter a value between 1 and 10: ";
            cin >> displayResolution;
        }
    }
    short getDisplayResolution(){
        return displayResolution;
    }

};

class DeviceTouchPad : public DeviceBaseClass {
private:
    short touchPadSensitivity;
public:
    //touchPadSensitivity:n arvo 0 aluksi
    DeviceTouchPad() : touchPadSensitivity(0) {}
    void setTouchPadSensitivity() {
        cout << "Enter touchpad sensitivity (1-5): ";
        cin >> touchPadSensitivity;
        //Ehtolause käyttäjän syötteelle
        while (touchPadSensitivity < 1 || touchPadSensitivity > 5 ) {
            cout << "Invalid input. Please enter a value between 1 and 5: ";
            cin >> touchPadSensitivity;
        }
    }
    short getTouchPadSensitivity(){
        return touchPadSensitivity;
    }
};

class MyDeviceUI {
private:
    DeviceMouse *objectDeviceMouse;
    DeviceTouchPad *objectDeviceTouchPad;
    DeviceDisplay *objectDeviceDisplay;

public:
    MyDeviceUI(){

        objectDeviceMouse = new DeviceMouse();
        objectDeviceTouchPad = new DeviceTouchPad();
        objectDeviceDisplay = new DeviceDisplay();
    }

    void uishowMenu(){
        cout << "Device Menu" << endl;
        cout << "===========" << endl;
        cout << "1: Set Mouse Information" << endl;
        cout << "2: Set Touchpad Information" << endl;
        cout << "3: Set Display Information" << endl;
        cout << "4: Show Devices Information" << endl;
        cout << "5: Finish" << endl;
        cout << "Choose: ";
    }

    void uiSetMouseInformation(){
        cout << "SET MOUSE INFORMATION" << endl;
        cout << "=====================" << endl;
        objectDeviceMouse->setDeviceID();
        objectDeviceMouse->setPrimaryButton();
    }
    void uiSetTouchPadInformation(){
        cout << "SET TOUCHPAD INFORMATION" << endl;
        cout << "=====================" << endl;
        objectDeviceTouchPad->setDeviceID();
        objectDeviceTouchPad->setTouchPadSensitivity();
    }
    void uiSetDisplayInformation(){
        cout << "SET DISPLAY INFORMATION" << endl;
        cout << "=====================" << endl;
        objectDeviceDisplay->setDeviceID();
        objectDeviceDisplay->setDisplayResolution();
    }
    void uiShowDeviceInformation() {

        cout << "Device Information" << endl;
        cout << "=================" << endl;

        cout << "\nMouse Information:" << endl;
        cout << "Device ID: " << objectDeviceMouse->getDeviceID() << endl;
        cout << "Primary Button: " << objectDeviceMouse->getPrimaryButton() << endl;

        cout << "\nTouchpad Information:" << endl;
        cout << "Device ID: " << objectDeviceTouchPad->getDeviceID() << endl;
        cout << "Touchpad Sensitivity: " << objectDeviceTouchPad->getTouchPadSensitivity() << endl;

        cout << "\nDisplay Information:" << endl;
        cout << "Device ID: " << objectDeviceDisplay->getDeviceID() << endl;
        cout << "Display Resolution: " << objectDeviceDisplay->getDisplayResolution() << endl;
        cout << endl;
    }

    ~MyDeviceUI(){

        delete objectDeviceMouse;
        delete objectDeviceTouchPad;
        delete objectDeviceDisplay;
    }
};

int main()
{
    MyDeviceUI deviceUI;
    int choice;
    do {
        deviceUI.uishowMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            deviceUI.uiSetMouseInformation();
            break;
        case 2:
            deviceUI.uiSetTouchPadInformation();
            break;
        case 3:
            deviceUI.uiSetDisplayInformation();
            break;
        case 4:
            deviceUI.uiShowDeviceInformation();
            break;
        case 5:
            cout << "Bye" << endl;
            break;
        default:
            cout << "Invalid choice. Please choose again." << endl;
        }
    } while (choice != 5);

    return 0;
}
