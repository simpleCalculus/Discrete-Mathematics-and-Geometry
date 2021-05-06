import java.util.Scanner;

public class Main {
    static int ctoi(char c) {
        if (c >= '0' && c <= '9')
            return c - '0';
        return c - 'A' + 10;
    }

    static boolean check(String s, int i) {
        int c = 1;
        int r = 0;
        for (int j = s.length() - 1; j >= 0; j--) {
            if (i <= ctoi(s.charAt(j))) {
                return false;
            }
            r = (r + c * ctoi(s.charAt(j))) % (i - 1);
            c = (c * i) % (i - 1);
        }
        return (r == 0);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String num = in.next();
        for (int i = 2; i <= 36; ++i) {
            if (check(num, i)) {
                System.out.println((i));
                System.exit(0);
            }
        }
        System.out.println("No solution.");
    }
}
