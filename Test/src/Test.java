import java.io.*;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File file=new File("files/imooc/1.txt");
		System.out.println(file.isDirectory());
		System.out.println(file.isFile());
		System.out.println(file.exists());
		if(!file.exists())
			try {
				file.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		System.out.println(file);
		System.out.println(file.getAbsolutePath());
		System.out.println(file.getName());
		System.out.println(file.getParent());
		System.out.println(file.getAbsoluteFile().getAbsolutePath());
		File file0=new File("files/im/tt");
		if(!file0.exists())
			file0.mkdirs();//创建多级目录mkdir()创建单一目录
	}

}
