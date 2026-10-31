
import java.util.Scanner;

abstract class Cab {
    double km;

    Cab(double km) {
        this.km = km;
    }

    abstract double getRate();

    double calculateFare() {
        double fare = km * getRate();

        if (fare < 100) {
            fare = 100;
        }

        return fare;
    }
}

interface NightService {
    default double nightFare(double fare) {
        return fare * 1.20;
    }
}

class Mini extends Cab {
    Mini(double km) {
        super(km);
    }

    double getRate() {
        return 10;
    }
}

class Sedan extends Cab implements NightService {
    Sedan(double km) {
        super(km);
    }

    double getRate() {
        return 14;
    }
}

class SUV extends Cab implements NightService {
    SUV(double km) {
        super(km);
    }

    double getRate() {
        return 18;
    }
}

public class Q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        double total = 0;

        for (int i = 0; i < n; i++) {
            String type = sc.next();
            double km = sc.nextDouble();
            String time = sc.next();

            Cab c = null;

            if (type.equals("MINI")) {
                c = new Mini(km);
            }
            else if (type.equals("SEDAN")) {
                c = new Sedan(km);
            }
            else if (type.equals("SUV")) {
                c = new SUV(km);
            }

            if (c == null) {
                continue;
            }

            if (time.equals("NIGHT") && c instanceof Mini) {
                System.out.println("MINI: night service not available");
                continue;
            }

            double fare = c.calculateFare();

            if (time.equals("NIGHT")) {
                fare = ((NightService) c).nightFare(fare);
            }

            System.out.printf("%s: %.2f%n", type, fare);
            total += fare;
        }

        System.out.printf("Total: %.2f%n", total);

        sc.close();
    }
}