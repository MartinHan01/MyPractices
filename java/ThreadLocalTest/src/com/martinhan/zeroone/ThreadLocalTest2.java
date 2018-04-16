package com.martinhan.zeroone;

public class ThreadLocalTest2 {
	
	public static void main(String[] args) {
		Num2 num = new Num2();
		Thread aThread = new Thread(){
			
			@Override
			public void run() {
				try {
					Thread.sleep(100L);
					num.setValue(100);
					num.addValue(200);
					System.out.println("thread ---" + Thread.currentThread() + " value is " + num.getValue());
				} catch (InterruptedException e) {
					e.printStackTrace();
				};
			}
		};
		Thread bThread = new Thread(){
			
			@Override
			public void run() {
				try {
					Thread.sleep(100L);
					num.setValue(100);
					num.addValue(400);
					System.out.println("thread ---" + Thread.currentThread() + " value is " + num.getValue());
				} catch (InterruptedException e) {
					e.printStackTrace();
				};
			}
		};
		aThread.start();
		bThread.start();
	}
}
