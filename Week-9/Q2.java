import java.util.Scanner;

abstract class Parcel {
    double weight, value;

    Parcel(double weight, double value) {
        this.weight = weight;
        this.value = value;
    }

    abstract double getCharge();

    double getInsurance() {
        return 0;
    }
}

interface Insurable {
    double getInsurance();
}

class Standard extends Parcel {
    Standard(double w, double v) {
        super(w, v);
    }

    double getCharge() {
        return 40 + 10 * weight;
    }
}

class Express extends Parcel implements Insurable {
    Express(double w, double v) {
        super(w, v);
    }

    double getCharge() {
        return 80 + 15 * weight;
    }

    public double getInsurance() {
        return value * 0.02;
    }
}

class Fragile extends Parcel implements Insurable {
    Fragile(double w, double v) {
        super(w, v);
    }

    double getCharge() {
        return 40 + 10 * weight + 50;
    }

    public double getInsurance() {
        return value * 0.02;
    }
}

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        double grandTotal = 0;

        for (int i = 0; i < n; i++) {
            String type = sc.next();
            double weight = sc.nextDouble();
            double value = sc.nextDouble();

            Parcel p = null;

            if (type.equals("STANDARD")) {
                p = new Standard(weight, value);
            }
            else if (type.equals("EXPRESS")) {
                p = new Express(weight, value);
            }
            else if (type.equals("FRAGILE")) {
                p = new Fragile(weight, value);
            }

            if (p != null) {
                double charge = p.getCharge();
                double insurance = p.getInsurance();
                double total = charge + insurance;

                System.out.printf(
                    "%s: Charge=%.2f Insurance=%.2f Total=%.2f%n",
                    type, charge, insurance, total
                );

                grandTotal += total;
            }
        }

        System.out.printf("Grand Total: %.2f%n", grandTotal);

        sc.close();
    }
}
