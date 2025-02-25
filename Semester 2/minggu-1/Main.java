import java.util.Arrays;
import java.util.ArrayList;
import java.util.Arrays;

class DaftarNama {
    private String[] nama;
    
    public DaftarNama(String[] nama) {
        this.nama = nama;
    }
    
    public void tampilkanNama() {
        for (String n : nama) {
            System.out.println(n);
        }
    }

    public boolean cariNama(String keyword) {
        for (String n : nama) {
            if (n.equalsIgnoreCase(keyword)) {
                return true;
            }
        }

    return false;

    }

    public void urutkanNama() {
        Arrays.sort(nama);
    }
}

public class Main {
    public static void main(String[] args) {
        String[] data = {"Andi", "Budi", "Citra", "Dewi", "Eka"};
        DaftarNama dn = new DaftarNama(data);
        dn.urutkanNama();
        dn.tampilkanNama();
        System.out.println("Apakah 'Dewi' ada? " + dn.cariNama("Dewi"));
    }
}

class StringPerformanceTest {
    public static void main(String[] args) {
        long startTime, endTime;
        // Menggunakan String
        String teks = "";
        startTime = System.nanoTime();
        for (int i = 0; i < 10000; i++) {
            teks += "-";
        }
        endTime = System.nanoTime();
        System.out.println("Runtime String: " + (endTime - startTime) + "ns");
        
        // Menggunakan StringBuilder
        StringBuilder sb = new StringBuilder();
        startTime = System.nanoTime();
        for (int i = 0; i < 10000; i++) {
            sb.append("-");
        }
        endTime = System.nanoTime();
        System.out.println("Runtime StringBuilder: " + (endTime - startTime) + " ns");
    }
}


class StringImmutableTest {
    public static void main(String[] args) {
        String teks = "Java";
        teks += " Programming"; // Modifikasi
        System.out.println(teks);
    }
}

class StringBuilderTest {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("Java");
        sb.append(" Programming"); // Modifikasi
        System.out.println(sb);
    }
}


class MemoryUsageTest {
    public static void main(String[] args) {
        long startTime, endTime;

        // Array Primitif
        startTime = System.nanoTime();
        int[] angkaArray = new int[1000000]; // 1 juta elemen
        for (int i = 0; i < angkaArray.length; i++) {
            angkaArray[i] = i;
        }
        endTime = System.nanoTime();
        System.out.println("Runtime array: "+(endTime - startTime)+" ns");
        // ArrayList
        startTime = System.nanoTime();
        ArrayList<Integer> angkaList = new ArrayList<>(1000000);
        for (int i = 0; i < 1000000; i++) {
            angkaList.add(i);
        }
        endTime = System.nanoTime();
        System.out.println("Runtime ArrayList: "+(endTime - startTime)+" ns");
    }
}


class JaggedArrayTest {
    public static void main(String[] args) {
        int[][] jaggedArray = {
            {1, 2, 3},
            {4, 5},
            {6, 7, 8, 9}
        };

        for (int i = 0; i < jaggedArray.length; i++) {
            for (int j = 0; j < jaggedArray[i].length; j++) {
                System.out.print(jaggedArray[i][j] + " ");
            }
                System.out.println();
        }
    }
}


class ArrayCopyTest {
    public static void main(String[] args) {
        int[] arrAsli = {1, 2, 3, 4, 5};// Referensi langsung
        int[] arrReferensi = arrAsli;
        
        // Salinan manual
        int[] arrManual = new int[arrAsli.length];
        
        for (int i = 0; i < arrAsli.length; i++) {
            arrManual[i] = arrAsli[i];
        }
 
        // Salinan menggunakan clone()
        int[] arrClone = arrAsli.clone();
        
        // Modifikasi array asli
        arrAsli[0] = 99;
        
        // Output
        System.out.println("Array asli: " + Arrays.toString(arrAsli));
        System.out.println("Array referensi: " + Arrays.toString(arrReferensi));
        System.out.println("Array manual: " + Arrays.toString(arrManual));
        System.out.println("Array clone: " + Arrays.toString(arrClone));
        }
}

class ArrayReference {
    public static void ubahArray(int[] arr) {
        arr[0] = 99;
    }
    public static void main(String[] args) {
        int[] angka = {1, 2, 3, 4, 5};
        
        System.out.println("Sebelum perubahan: " + angka[0]);
        ubahArray(angka);
        System.out.println("Setelah perubahan: " + angka[0]);
    }
}
