
import java.util.Scanner;

abstract class Appliance {
    abstract double getPower();

    double getUnits(double hours) {
        return getPower() * hours / 1000;
    }
}

interface SaverMode {
    default double saverUnits(double units) {
        return units * 0.75;
    }
}

class Fridge extends Appliance {
    double getPower() {
        return 150;
    }
}

class AC extends Appliance implements SaverMode {
    double getPower() {
        return 1500;
    }
}

class TV extends Appliance {
    double getPower() {
        return 100;
    }
}

class Washer extends Appliance implements SaverMode {
    double getPower() {
        return 500;
    }
}

public class Q5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        double total = 0;

        for (int i = 0; i < n; i++) {
            String type = sc.next();
            double hours = sc.nextDouble();

            boolean saver = false;

            if (sc.hasNext("SAVER")) {
                sc.next();
                saver = true;
            }

            Appliance a = null;

            if (type.equals("FRIDGE")) {
                a = new Fridge();
            }
            else if (type.equals("AC")) {
                a = new AC();
            }
            else if (type.equals("TV")) {
                a = new TV();
            }
            else if (type.equals("WASHER")) {
                a = new Washer();
            }

            if (a == null) {
                continue;
            }

            if (saver && !(a instanceof SaverMode)) {
                System.out.println(type + ": saver mode not supported");
                continue;
            }

            double units = a.getUnits(hours);

            if (saver) {
                units = ((SaverMode) a).saverUnits(units);
            }

            double cost = units * 8;

            System.out.printf(
                "%s: Units=%.2f Cost=%.2f%n",
                type, units, cost
            );

            total += cost;
        }

        System.out.printf("Total Cost: %.2f%n", total);

        sc.close();
    }
}