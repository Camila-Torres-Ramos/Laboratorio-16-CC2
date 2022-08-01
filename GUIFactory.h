#if !defined(_GUIFACTORY_H_)
#define _GUIFACTORY_H_

#include <iostream>         

class WinFactory {
    public:
    virtual ~WinFactory() {};
    virtual std::string Draw() const = 0;
};

class WinButton : public WinFactory {
    public:
    std::string Draw() const override {
        return "Dibujando Button Windows.";
    }
};

class WinCheckBox : public WinFactory {
    std::string Draw() const override {
        return "Dibujando CheckBox Windows.";
    }
};

class MacFactory {
    public:
    virtual ~MacFactory() {};
    virtual std::string Draw() const = 0;
    virtual std::string draw(const WinFactory& colaborador) const = 0;
};

class MacButton : public MacFactory {
    public:
    std::string Draw() const override {
        return "Dibujando Button Mac.";
    }

    std::string draw(const WinFactory& colaborador) const override {
        const std::string result = colaborador.Draw();
        return "Dibujando Button Mac con ayuda de " + result;
    }
};

class MacCheckBox : public MacFactory {
    public:
    std::string Draw() const override {
        return "Dibujando CheckBox Mac.";
    }

    std::string draw(const WinFactory& colaborador) const override {
        const std::string result = colaborador.Draw();
        return "Dibujando CheckBox Mac con ayuda de " + result;
    }
};

class LinuxFactory {
    public:
    virtual ~LinuxFactory() {};
    virtual std::string Draw() const = 0;
    virtual std::string draw(const WinFactory& colaborador) const = 0;
};

class LinuxButton : public LinuxFactory {
    public:
    std::string Draw() const override {
        return "Dibujando Button Linux.";
    }

    std::string draw(const WinFactory& colaborador) const override {
        const std::string result = colaborador.Draw();
        return "Dibujando Button Linux con ayuda de " + result;
    }
};

class LinuxCheckBox : public LinuxFactory {
    public:
    std::string Draw() const override {
        return "Dibujando CheckBox Linux.";
    }

    std::string draw(const WinFactory& colaborador) const override {
        const std::string result = colaborador.Draw();
        return "Dibujando CheckBox Linux con ayuda de " + result;
    }
};

class GUIFactory {
    public:
    virtual WinFactory* CrearControlW() const = 0;
    virtual MacFactory* CrearControlM() const = 0;
    virtual LinuxFactory* CrearControlL() const = 0;
};

class Button : public GUIFactory {
    public:
    WinFactory* CrearControlW() const override {
        return new WinButton();
    }

    MacFactory* CrearControlM() const override {
        return new MacButton();
    }

    LinuxFactory* CrearControlL() const override {
        return new LinuxButton();
    }
};

class CheckBox : public GUIFactory {
    public:
    WinFactory* CrearControlW() const override {
        return new WinCheckBox();
    }

    MacFactory* CrearControlM() const override {
        return new MacCheckBox();
    }

    LinuxFactory* CrearControlL() const override {
        return new LinuxCheckBox();
    }
};

#endif 
