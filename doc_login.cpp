
#include <TGUI/TGUI.hpp>
#include <iostream>
#include"Doctor.h"
#include<stack>
#include"print.h"
Doctor d;
auto editBoxUsername = tgui::EditBox::create();
auto editBoxPassword = tgui::EditBox::create();
auto chatbox         = tgui::ChatBox::create();
auto button          = tgui::Button::create("Login");
auto Delete_all      = tgui::Button::create("Clear DB");
auto print           = tgui::Button::create("Print");

void delete_slots()
{

}
void print_app()
{
    stack<string>s = d.print(conn);
     while(!s.empty())
        {
    print_pres(s.top(),d.getid(),d.getdept());
    s.pop();
    }

}
void login()
{
    std::cout << "Username: " <<editBoxUsername->getText().toAnsiString()<< std::endl;
    std::cout << "Password: " << editBoxPassword->getText().toAnsiString()<< std::endl;
    int x = d.login(conn,editBoxUsername->getText().toAnsiString(),editBoxPassword->getText().toAnsiString());
    if(x==1)
    {
        editBoxPassword->setVisible(false);
        editBoxUsername->setVisible(false);
        button->setVisible(false);
        chatbox->setVisible(true);
        Delete_all->setVisible(true);
        print->setVisible(true);
        chatbox->addLine("\t\t\t Your Appointments are \t", sf::Color::Black);
        chatbox->addLine(d.display_appointments(conn), sf::Color::Red);

    }



}


void loadWidgets( tgui::Gui& gui )
{

    auto picture = tgui::Picture::create("BgOOPS.jpg");
    picture->setSize({"100%", "100%"});
    gui.add(picture);



    editBoxUsername->setSize({"66.67%", "12.5%"});
    editBoxUsername->setPosition({"16.67%", "16.67%"});
    editBoxUsername->setDefaultText("Username");
    editBoxUsername->setVisible(true);
    gui.add(editBoxUsername);


    editBoxPassword->setSize({"66.67%", "12.5%"});
    editBoxPassword->setPosition({"16.67%", "41.6%"});
    editBoxPassword->setPasswordCharacter('*');
    editBoxPassword->setDefaultText("Password");
    editBoxPassword->setVisible(true);
    gui.add(editBoxPassword);

    // Create the login button

    button->setSize({"50%", "16.67%"});
    button->setPosition({"25%", "70%"});
    button->setVisible(true);
    gui.add(button);
    button->connect("pressed", login);

    Delete_all->setSize({"35%", "9.67%"});
    Delete_all->setPosition({"16.67%", "70%"});
    Delete_all->setVisible(false);
    gui.add(Delete_all);
    Delete_all->connect("pressed", delete_slots);



    print->setSize({"35%", "9.67%"});
    print->setPosition({"52.67%", "70%"});
    print->setVisible(false);
    gui.add(print);
    print->connect("pressed", print_app);




        chatbox->setSize({"66.67%", "50.5%"});
        chatbox->setTextSize(16);
        chatbox->setPosition({"16.67%", "16.67%"});
        chatbox->setLinesStartFromTop();
        chatbox->setVisible(false);
        gui.add(chatbox);
}

int main()
{
    conn  = mysql_init(0);//connecting to database
    conn =mysql_real_connect(conn,"remotemysql.com", "izbe2a6Gri","9MnXblPN0F","izbe2a6Gri",3306,NULL,0);

    if(conn==0)
    {
        cout<<"Error\n";
        mysql_close(conn);
        exit(0);
    }
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "TGUI window");
    tgui::Gui gui(window);

    try
    {
        loadWidgets(gui);
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return 1;
    }

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // When the window is closed, the application ends
            if (event.type == sf::Event::Closed)
                window.close();

            // When the window is resized, the view is changed
            else if (event.type == sf::Event::Resized)
            {
                window.setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(event.size.width), static_cast<float>(event.size.height))));
                gui.setView(window.getView());
            }

            // Pass the event to all the widgets
            gui.handleEvent(event);
        }

        window.clear();

        // Draw all created widgets
        gui.draw();

        window.display();
    }

    return EXIT_SUCCESS;
}
