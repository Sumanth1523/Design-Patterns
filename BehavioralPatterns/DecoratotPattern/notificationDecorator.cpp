#include <iostream>
using namespace std;


class Notifier
{
    public:
        virtual void send(){
            cout << "Email Notification Sent" << endl;
        }
};

class EmailNotifier
{
    public:
        virtual void send(){
            cout << "Email Notification Sent" << endl;
        }
};

class SMSNotifier: public Notifier
{
    public:
        void send(){
            cout << "SMS Notification Sent" << endl;
        }
};

class FaceBookNotifier: public Notifier
{
    public:
        void send(){
            cout << "Facebook Notification Sent" << endl;
        }
};

class SlackNotifier: public Notifier
{
    public:
        void send(){
            cout << "Slack Notification Sent" << endl;
        }
};


class OutlookNotifier: public Notifier final
{
    public:
        void send(){
            cout << "Outlook Notification Sent" << endl;
        }
};

class BaseDecorator: public Notifier{
    private:
        Notifier* notifier;
        
    public:

        BaseDecorator(Notifier* notifier)
        {
            this->notifier = notifier;
        }

        void send(){
            if(notifier != nullptr)
                notifier->send();
        }

        ~BaseDecorator()
        {
            if(notifier)
            {
                delete notifier;
            }
        }
};

class SMSDecorator: public BaseDecorator{
    private:
        Notifier* notifier;
    public:

        SMSDecorator(Notifier* notifier): BaseDecorator(notifier)
        {
            this->notifier = new SMSNotifier;
        }
        void send(){
            BaseDecorator::send();
            if(notifier != nullptr)
                this->notifier->send();
        }

        ~SMSDecorator()
        {
            if(notifier)
            {
                delete notifier;
            }
        }
};


class FacebookDecorator: public BaseDecorator{
    private:
        Notifier* notifier;
    public:
        FacebookDecorator(Notifier* notifier): BaseDecorator(notifier)
        {
            this->notifier = new FaceBookNotifier;
        }
        void send(){
            BaseDecorator::send();
            if(notifier != nullptr)
                notifier->send();
        }

        ~FacebookDecorator()
        {
            if(notifier)
            {
                delete notifier;
            }
        }
};

class SlackDecorator: public BaseDecorator{
    private:
        Notifier* notifier;
    public:
        SlackDecorator(Notifier* notifier): BaseDecorator(notifier)
        {
            this->notifier = new SlackNotifier;
        }
        void send(){
            BaseDecorator::send();
            if(notifier != nullptr)
                notifier->send();            
        }

        ~SlackDecorator()
        {
            if(notifier)
            {
                delete notifier;
            }
        }
};


class OutlookDecorator: public BaseDecorator{
    private:
        Notifier* notifier;
    public:
        OutlookDecorator(Notifier* notifier): BaseDecorator(notifier)
        {
            this->notifier = new OutlookNotifier;
        }
        void send(){
            BaseDecorator::send();
            if(notifier != nullptr)
                notifier->send();            
        }

        ~OutlookDecorator()
        {
            if(notifier)
            {
                delete notifier;
            }
        }
};

int main()
{
    //Notifier* notifier =  new SMSDecorator(new SlackNotifier); // SMS -> Email
    Notifier* notifier =  new FacebookDecorator(nullptr); // FaceBook -> SMS -> EMail
    notifier = new SlackDecorator(notifier); // Slack -> FaceBook -> SMS -> EMail
    notifier = new OutlookDecorator(notifier);

    notifier->send();


    delete notifier;
    return 0;
}

