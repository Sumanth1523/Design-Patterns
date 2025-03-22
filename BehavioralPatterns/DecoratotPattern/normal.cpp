#include <iostream>
using namespace std;


class Notifier
{
    public:
        virtual void send(){
            cout << "Email Notification Sent" << endl;
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

class FaceBookNEmailNotifier
{
    private:
        Notifier* emailNotifier;
        Notifier* facebookNotifier;
    public:
        FaceBookNEmailNotifier()
        {
            emailNotifier = new Notifier;
            facebookNotifier = new FaceBookNotifier;
        }

        void send()
        {
            emailNotifier->send();
            facebookNotifier->send();
        }

        ~FaceBookNEmailNotifier()
        {
            delete emailNotifier;
            delete facebookNotifier;
        }
};

class FacebookNSlackNotifier
{
    private:
        Notifier* slackNotifier;
        Notifier* facebookNotifier;
    public:

        FacebookNSlackNotifier()
        {
            slackNotifier = new SlackNotifier;
            facebookNotifier = new FaceBookNotifier;
        }
        
        void send()
        {
            slackNotifier->send();
            facebookNotifier->send();
        }

        ~FacebookNSlackNotifier()
        {
            delete slackNotifier;
            delete facebookNotifier;
        }
};

class FaceBookEmailNSlackNotifier
{
    private:
        Notifier* emailNotifier;
        Notifier* slackNotifier;
        Notifier* facebookNotifier;
    public:
        FaceBookEmailNSlackNotifier()
        {
            emailNotifier = new Notifier;
            slackNotifier = new SlackNotifier;
            facebookNotifier = new FaceBookNotifier;
        }
        
        void send()
        {
            emailNotifier->send();
            slackNotifier->send();
            facebookNotifier->send();
        }

        ~FaceBookEmailNSlackNotifier()
        {
            delete emailNotifier;
            delete slackNotifier;
            delete facebookNotifier;
        }
};




// A Decorator is like a Composite but only has one child component.
//  There’s another significant difference: Decorator adds additional responsibilities to the wrapped object, 
//  while Composite just “sums up” its children’s results.

int main()
{
    FacebookNSlackNotifier faceBookEmailNSlackNotifier;
    faceBookEmailNSlackNotifier.send();
    return 0;
}

