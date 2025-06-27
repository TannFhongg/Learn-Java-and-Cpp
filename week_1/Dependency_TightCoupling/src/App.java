public class App {

    public static void main(String[] args) throws Exception {

        EmailService emailService = new EmailService();
        SMSService smsService = new SMSService();

        Client client = new Client();
        client.setService(smsService);
        client.processMessage("Hello, World");

    }
}
