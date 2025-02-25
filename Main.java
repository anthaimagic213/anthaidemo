import java.util.Scanner;
public class Main {
    


    public static void main(String[] args) {

        Scanner  scanner = new Scanner(System.in);
        int n=scanner.nextInt();
        if(n%2==1){
            System.out.println("so le");

        }
        else {
            System.out.println("so chan");
        }
        scanner.close();
    }

}