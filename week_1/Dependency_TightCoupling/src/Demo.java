 interface  DichVuTinNhan {
public void guiTinNhan(String message);
}


class DichVuEmail implements DichVuTinNhan {
    
    public void guiTinNhan(String message) {
        System.out.println("Gui tin nhan voi email: " + message);
    }
}
class DichVuSMS implements DichVuTinNhan {
    public void guiTinNhan(String message) {
        System.out.println("Gui tin nhan voi sms: "+ message);
    }
}
interface InjectionDichVuTinNhan  {

    public void setTinNhan(DichVuTinNhan dichVuTinNhan); 
}


class KhachHang implements InjectionDichVuTinNhan {
    DichVuTinNhan dichVuTinNhan; 
/*  // Constructor injection
    KhachHang(DichVuTinNhan dichVuTinNhan) {
        this.dichVuTinNhan = dichVuTinNhan;
    }
*/
/* // setter injection
public void setDichVuTinNhan(DichVuTinNhan dichVuTinNhan) {
    this.dichVuTinNhan = dichVuTinNhan; 
}
*/

// interface injection
@Override 
public void setTinNhan(DichVuTinNhan dichVuTinNhan) {
    this.dichVuTinNhan = dichVuTinNhan; 
}

    public void processMessage(String message) {
        dichVuTinNhan.guiTinNhan(message);
    }



}
public class Demo {
    public static void main(String[] args) {
        DichVuEmail dichVuEmail = new DichVuEmail(); 
        DichVuSMS dichVuSMS = new DichVuSMS(); 

        KhachHang khachHang = new KhachHang();
        khachHang.setTinNhan(dichVuSMS);
       // khachHang.setDichVuTinNhan(dichVuSMS);

        khachHang.processMessage("Hello, World"); 
    }
}
