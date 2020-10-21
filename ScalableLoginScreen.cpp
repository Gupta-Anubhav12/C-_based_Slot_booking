
#include <TGUI/TGUI.hpp>
#include <iostream>



// widgets are declared Globally to avoid confusion while calling in functions
    auto btn_otp            = tgui::Button::create("verify OTP");
    auto combo_day          = tgui::ComboBox::create();
    auto combo_doc          = tgui::ComboBox::create();
    auto combo_gender       = tgui::ComboBox::create();
    auto combo_slots        = tgui::ComboBox::create();
    auto loginAcc           = tgui::Button::create("Sign In");
    auto editBoxUsername    = tgui::EditBox::create();
    auto editBoxOtp         = tgui::EditBox::create();
    auto editBoxAge         = tgui::EditBox::create();
    auto createAcc          = tgui::Button::create("Create Account");
    auto btn_login          = tgui::Button::create("Already Have Account");
    auto btn_register       = tgui::Button::create("Register");
    auto btn_book           = tgui::Button::create("Book a Slot");
    auto btn_delete         = tgui::Button::create("Delete Appointment");
    auto btn_show           = tgui::Button::create("Show Current Slots");
    auto btn_dayDoc         = tgui::Button::create("Show Available Slots");
    auto btn_allot          = tgui::Button::create("Book Slot ");

    auto lab_pass           = tgui::Label::create();
    auto lab_otp            = tgui::Label::create();



void register_otp(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password,tgui::EditBox::Ptr password2,tgui::EditBox::Ptr otp)
{
  std::cout<<"adasad";
  std::cout << "OTP is " << otp->getText().toAnsiString() << std::endl;
  if(otp->getText().toAnsiString()!="1234")
    lab_otp->setVisible(true);
  if(otp->getText().toAnsiString()=="1234"){

        lab_otp->setVisible(false);
        editBoxUsername->setVisible(false);
        loginAcc->setVisible(false);
        btn_book->setVisible(true);
        password->setVisible(false);

        btn_delete->setVisible(true);
        btn_show->setVisible(true);
        combo_gender->setVisible(false);
        editBoxAge->setVisible(false);
        password2->setVisible(false);
        btn_otp->setVisible(false);
        editBoxOtp->setVisible(false);


        }


}


// to render slots in combox
void fun_slot(void){

    combo_slots->setVisible(true);
    btn_allot->setVisible(true);

}

//finally Book the slot here
void fun_final(void){



}
//function for Booking Slot

void fun_book(void){
    btn_book->setVisible(false);
    btn_show->setVisible(false);
    btn_delete->setVisible(false);
    combo_day->addItem("Item 4");
    combo_day->setVisible(true);
    combo_doc->setVisible(true);
    btn_dayDoc->setVisible(true);




}
// function for deleting
void fun_show(void){

    btn_book->setVisible(false);
    btn_show->setVisible(false);
    btn_delete->setVisible(false);

}
void fun_delete(void){


    btn_book->setVisible(false);
    btn_show->setVisible(false);
    btn_delete->setVisible(false);
}

//this function validates the password matching and renders the otp textbox this function is also used to trace Email and send OPT
// Gagan Do take a note of this

void register_acc(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password,tgui::EditBox::Ptr password2,tgui::EditBox::Ptr otp)
{
    std::cout << "Username: " << username->getText().toAnsiString() << std::endl;
    std::cout << "Password: " << password->getText().toAnsiString() << std::endl;
    std::cout << "Password2: " << password2->getText().toAnsiString() << std::endl;
    std::cout << "Gender: " << combo_gender->getSelectedItem().toAnsiString()<< std::endl;
    std::cout << "Age: " << editBoxAge->getText().toAnsiString()<< std::endl;
    if( password->getText().toAnsiString() == password2->getText().toAnsiString() ){
        otp->setVisible(true);
        btn_otp->setVisible(true);
        btn_register->setVisible(false);
    }
    else{
        lab_pass->setVisible(true);
    }

    std::cout << "otp: " << otp->getText().toAnsiString() << std::endl;
}


void login_acc(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password)
{
    std::cout<<"aa rha ethe rt";
    std::cout << "Username: " << username->getText().toAnsiString() << std::endl;
    std::cout << "Password: " << password->getText().toAnsiString() << std::endl;
    //Gagan will add validation from database here to register the user and store his/her data in variables
    editBoxUsername->setVisible(false);
    loginAcc->setVisible(false);
    btn_book->setVisible(true);
    password->setVisible(false);

    btn_delete->setVisible(true);
    btn_show->setVisible(true);



}


void loadWidgets( tgui::Gui& gui )


{

    // Create the background image
    // The picture is of type tgui::Picture::Ptr which is actually just a typedef for std::shared_widget<Picture>
    // The picture will fit the entire window and will scale with it
    auto picture = tgui::Picture::create("BgOOPS.jpg");
    picture->setSize({"100%", "100%"});
    gui.add(picture);

    // Create the username edit box
    // Similar to the picture, we set a relative position and size
    // In case it isn't obvious, the default text is the text that is displayed when the edit box is empty

    editBoxUsername->setSize({"40%", "6%"});
    editBoxUsername->setPosition({"29%", "18%"});
    editBoxUsername->setDefaultText("Username");
    editBoxUsername->setVisible(false);
    gui.add(editBoxUsername);

    // Create the password edit box
    // We copy the previous edit box here and keep the same size
    auto editBoxPassword = tgui::EditBox::copy(editBoxUsername);
    editBoxPassword->setPosition({"29%", "26%"});
    editBoxPassword->setPasswordCharacter('*');
    editBoxPassword->setDefaultText("Password");
    gui.add(editBoxPassword);

    auto editBoxPassword2 = tgui::EditBox::copy(editBoxUsername);
    editBoxPassword2->setPosition({"29%", "34%"});
    editBoxPassword2->setPasswordCharacter('*');
    editBoxPassword2->setDefaultText("Confirm  Password");
    gui.add(editBoxPassword2);


    //editbox and button for otp entry and calls a function for validation


    editBoxOtp->setSize({"26.67%", "6.5%"});
    editBoxOtp->setPosition({"0.67%", "0.67%"});
    editBoxOtp->setDefaultText("Otp");
    editBoxOtp->setVisible(false);
    gui.add(editBoxOtp);




    //Edit box here is used to get Age of user during registration
    editBoxAge->setSize({"26%", "6%"});
    editBoxAge->setPosition({"29%", "42%"});
    editBoxAge->setDefaultText("Enter Age");
    editBoxAge->setVisible(false);
    gui.add(editBoxAge);
    // Create the login button

    btn_register->setSize({"50%", "16.67%"});
    btn_register->setPosition({"25%", "70%"});
    btn_register->setVisible(false);
    gui.add(btn_register);
    btn_register->connect("pressed", register_acc, editBoxUsername, editBoxPassword,editBoxPassword2,editBoxOtp);

    //bUTTON TO LOGIN INTO
    loginAcc->setSize({"50%", "16.67%"});
    loginAcc->setPosition({"25%", "70%"});
    loginAcc->setVisible(false);
    gui.add(loginAcc);
    loginAcc->connect("pressed",login_acc, editBoxUsername, editBoxPassword);


    //Button to Verify the OTP and process stuff in login ::
    btn_otp->setSize({"26.67%", "6.5%"});
    btn_otp->setPosition({"27.67%", "0.67%"});
    btn_otp->setVisible(false);
    gui.add(btn_otp);
    btn_otp->connect("pressed",register_otp, editBoxUsername, editBoxPassword,editBoxPassword2,editBoxOtp);



    //Buttons for creating appointment || for showing current bookings and for Deleting appointments
    btn_book->setSize({"28%", "12%"});
    btn_book->setPosition({"35%", "12%"});
    btn_book->setVisible(false);
    gui.add(btn_book);
    btn_book->connect("pressed",fun_book);


     btn_delete->setSize({"28%", "12%"});
    btn_delete->setPosition({"35%", "26%"});
    btn_delete->setVisible(false);
    gui.add(btn_delete);
    btn_delete->connect("pressed",fun_delete);


    btn_show->setSize({"28%", "12%"});
    btn_show->setPosition({"35%", "40%"});
    btn_show->setVisible(false);
    gui.add(btn_show);
    btn_show->connect("pressed",fun_show);




    //for final allotment of slot
    btn_allot->setSize({"28%", "6%"});
    btn_allot->setPosition({"67%", "56%"});
    btn_allot->setVisible(false);
    gui.add(btn_allot);
    btn_allot->connect("pressed",fun_show);



    //Button for selecting available slots
    btn_dayDoc->setSize({"28%", "6%"});
    btn_dayDoc->setPosition({"67%", "40%"});
    btn_dayDoc->setVisible(false);
    gui.add(btn_dayDoc);
    btn_dayDoc->connect("pressed",fun_slot);







    // Button to make choice for Login/Register goes here
    // first is for Register Option

    createAcc->setSize({"50%", "16.67%"});
    createAcc->setPosition({"25%", "70%"});
    createAcc->setVisible(true);
    gui.add(createAcc);
    createAcc->connect("pressed", [=](){ btn_register->setVisible(true);
                                        editBoxUsername->setVisible(true);
                                        editBoxPassword->setVisible(true);
                                        editBoxPassword2->setVisible(true);
                                        createAcc->setVisible(false);
                                        btn_login->setVisible(false);
                                        combo_gender->setVisible(true);
                                        editBoxAge->setVisible(true); });
    //button for choosing login

    btn_login->setSize({"50%", "16.67%"});
    btn_login->setPosition({"25%", "50%"});
    btn_login->setVisible(true);
    gui.add(btn_login);
    btn_login->connect("pressed", [=](){ loginAcc->setVisible(true);
                                        editBoxUsername->setVisible(true);
                                        editBoxPassword->setVisible(true);
                                        createAcc->setVisible(false);

                                        btn_login->setVisible(false);
                                         });




    // Call the login function when the button is pressed and pass the edit boxes that we created as parameters



    //drop down for gender selection in Register part

        combo_gender->setSize("26%","6%");
        combo_gender->setPosition("56%", "42%");
        combo_gender->addItem("M");
        combo_gender->addItem("F");
        combo_gender->setSelectedItem("M");
        combo_gender->setVisible(false);
        gui.add(combo_gender);


        // Combo Box for selecting Day of Week
        combo_day->setSize("28%", "6%");
        combo_day->setPosition("7%","40%");
        combo_day->addItem("Item 3");
        combo_day->setSelectedItem("Item 3");
        combo_day->setVisible(false);
        gui.add(combo_day);

        //combo box for doctors
        combo_doc->setSize("28%", "6%");
        combo_doc->setPosition("37%","40%");
        combo_doc->addItem("Item 3");
        combo_doc->setSelectedItem("Item 3");
        combo_doc->setVisible(false);
        gui.add(combo_doc);

        //Combo for showing available slots
        combo_slots->setSize("28%", "6%");
        combo_slots->setPosition("37%","56%");
        combo_slots->addItem("Item 3");
        combo_slots->setSelectedItem("Item 3");
        combo_slots->setVisible(false);
        gui.add(combo_slots);



        //Label for showing that passwords don't match


        lab_pass->setText("Passwords Don't Match");
        lab_pass->setPosition("36%","44%");
        lab_pass->setTextSize(22);
        lab_pass->setVisible(false);
        gui.add(lab_pass);

        //label for otp verification failure
        lab_otp->setText("Invalid OTP");
        lab_otp->setPosition("36%","44%");
        lab_otp->setTextSize(22);
        lab_otp->setVisible(false);
        gui.add(lab_otp);

}

int main()
{
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
