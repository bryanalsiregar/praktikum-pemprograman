import java.util.Scanner;

class Siswa {
    private String name;
    private int age;

    Siswa(String nama, int umur) {
        this.name = name;
        this.age = umur;
    }

    public void cetakNama() {
        System.out.println("Namaku: "+this.name);
    }
    public void cetakUmur() {
        System.out.println("Namaku: "+this.age);
    }
}

class MerekMobil {
    String[] mobil;
    
    MerekMobil(String[] mbl) {
        this.mobil = mbl;
    }

    public void cetakSemuaMobil() {
        for (int i = 0; i < this.mobil.length; i++) {
            System.out.println(this.mobil[i]);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.print("Masukkan Angka:");
            int angka = sc.nextInt();
            if (angka % 2 == 0) {
                System.out.println("Angka "+angka+" adalah Genap!");
            } else {
                System.out.println("Angka "+angka+" adalah Ganjil!");
            }
        }
        sc.close();
    }
}