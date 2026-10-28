import java.util.stream.LongStream;

public class Main {
	public static void main(String[] args) {
		long result = LongStream.rangeClosed(1, 20)
		.reduce(1L, (a, b) -> a * b);

		System.out.println(result);
	}
}
