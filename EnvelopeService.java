package com.example.broadcast;

import android.R.integer;
import android.accessibilityservice.AccessibilityService;  
import android.annotation.TargetApi;  
import android.app.Activity;
import android.app.Notification;  
import android.app.PendingIntent;  
import android.content.Context;
import android.os.Build;  
import android.os.Handler;  
import android.os.Parcelable;
import android.speech.tts.TextToSpeech;
import android.util.Log;  
import android.view.accessibility.AccessibilityEvent;  
import android.view.accessibility.AccessibilityManager;  
import android.view.accessibility.AccessibilityNodeInfo;  
import android.widget.Toast;  
  
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;  
import java.util.Locale;


  
/** 
 * <p>Created by Administrator</p> 
 * <p/> 
 * 抢红包外挂服务 
 */  
public class EnvelopeService extends AccessibilityService {  
  
    static final String TAG = "Jackie";  
  
    /** 
     * 微信的包名 
     */  
    static final String WECHAT_PACKAGENAME = "com.tencent.mm";  
    /** 
     * 红包消息的关键字 
     */  
    static final String ENVELOPE_TEXT_KEY = "[微信红包]";  
  
    Handler handler = new Handler();  
    
    
    public static final String OPEN_MONEY_PACK = "开";
    
    public static final String OPEN_MONEY_PACK_COM = "開";
    
    public static final String CHA_MONEY_PACK = "拆红包";
    
    private static String openMoneyPackType = "拆红包";
    
    public static Boolean needSpeck = true;
    
//    public static void updateOpenMoneyPackType(String type){
//    	openMoneyPackType = type;
//    	 
//    }
    
    private TextToSpeech mTextToSpeech = null;
    
    private Boolean hasLanguage = true;
    private void setSpeechLanguage(){
    	hasLanguage = false;
    	int supported = mTextToSpeech.setLanguage(languag[languagIndex]);
    	if((supported != TextToSpeech.LANG_AVAILABLE)&&(supported != TextToSpeech.LANG_COUNTRY_AVAILABLE)){
    		displayToast("不支持当前语言！");
    		languagIndex++;
    		if(languagIndex < languag.length){
    			setSpeechLanguage();
    		}
    	}
    	else
    	{
    		hasLanguage = true;
    	}
    	
    }
    
    private Locale[] languag;
    private int languagIndex = 0;
    
    public static Context ct;
    
    private void initServer(){
//    	openMoneyPackType = OPEN_MONEY_PACK;
    	
    	languag = new Locale[2];
    	languag[0] = Locale.CHINA;
    	languag[1] = Locale.CHINESE;
    	 //实例并初始化TTS对象
    	try{
    		mTextToSpeech = new TextToSpeech(ct, new TextToSpeech.OnInitListener() {
    			
    			@Override
    			public void onInit(int status) {
    				// TODO Auto-generated method stub
    				if(status == TextToSpeech.SUCCESS){
    					setSpeechLanguage();
    				}
    			}
    		});  
    	}
    	catch(Exception e){

    		Log.d(TAG, "error---->" + e.toString());  
    		if(ct == null){
    			Log.d(TAG, "ct == null---->");
    		}
    	}
    }
    
    private void displayToast(String info){
    	Toast.makeText(this, info, Toast.LENGTH_SHORT).show();
    }
    //-------------------- check pack- ----------------  
    @Override  
    public void onAccessibilityEvent(AccessibilityEvent event) {  
        final int eventType = event.getEventType();  
        Log.d(TAG, "事件---->" + event);  
        this.currentWindowName = "";
        //通知栏事件  
        if (eventType == AccessibilityEvent.TYPE_NOTIFICATION_STATE_CHANGED) {  
            List<CharSequence> texts = event.getText();  
            if (!texts.isEmpty()) {  
                for (CharSequence t : texts) {  
                    String text = String.valueOf(t);  
                    if (text.contains(ENVELOPE_TEXT_KEY)) {  
                        openNotification(event);  
                        break;  
                    }  
                }  
            }  
        } else if (eventType == AccessibilityEvent.TYPE_WINDOW_STATE_CHANGED) {  
            openEnvelope(event);  
        }  
    }  
  
    /*@Override 
    protected boolean onKeyEvent(KeyEvent event) { 
        //return super.onKeyEvent(event); 
        return true; 
    }*/  
  
    
//    private static EnvelopeService instance;
    
    @Override
    public void onCreate() {
    	// TODO Auto-generated method stub
    	super.onCreate();
    	Toast.makeText(this, "开启抢红包服务", Toast.LENGTH_SHORT).show();  
    }
    
    @Override  
    public void onInterrupt() {  
        Toast.makeText(this, "中断抢红包服务", Toast.LENGTH_SHORT).show();  
    }  
  
    @Override  
    protected void onServiceConnected() {  
        super.onServiceConnected();  
        Toast.makeText(this, "连接抢红包服务", Toast.LENGTH_SHORT).show();  
        this.initServer();
    }  
  
    public static void sendNotificationEvent(Context ct) {  
        AccessibilityManager manager = (AccessibilityManager) ct.getSystemService(ACCESSIBILITY_SERVICE);  
        if (!manager.isEnabled()) {  
            return;  
        }  
        AccessibilityEvent event = AccessibilityEvent.obtain(AccessibilityEvent.TYPE_NOTIFICATION_STATE_CHANGED);  
        event.setPackageName(WECHAT_PACKAGENAME);  
        event.setClassName(Notification.class.getName());  
        CharSequence tickerText = ENVELOPE_TEXT_KEY;  
        event.getText().add(tickerText);  
        manager.sendAccessibilityEvent(event);  
    }  
  
    /** 
     * 打开通知栏消息 
     */  
    @TargetApi(Build.VERSION_CODES.JELLY_BEAN)  
    private void openNotification(AccessibilityEvent event) {  
        if (event.getParcelableData() == null || !(event.getParcelableData() instanceof Notification)) {  
            return;  
        }  
        //以下是精华，将微信的通知栏消息打开  
        Notification notification = (Notification) event.getParcelableData();  
        PendingIntent pendingIntent = notification.contentIntent;  

        try {  
            pendingIntent.send();
             
        } catch (PendingIntent.CanceledException e) {  
            e.printStackTrace();  
        }  
    }  
    
    
    private static final String MONEY_RECIVER = "com.tencent.mm.plugin.luckymoney.ui.LuckyMoneyReceiveUI";
    
    private static final String MONEY_DETAIL = "com.tencent.mm.plugin.luckymoney.ui.LuckyMoneyDetailUI";
    
    private static final String LAUNCHER_UI = "com.tencent.mm.ui.LauncherUI";
    
    private static final String SEND_MONEY_PACK = "com.tencent.mm.plugin.luckymoney.ui.LuckyMoneyPrepareUI";
    
    private static final String PAY_MONEY_PACK = "com.tencent.mm.plugin.wallet.pay.ui.WalletPayUI";
    
    private Boolean tryToSendMoneyPack = false;
    
    private String currentWindowName = "null";
  
    @TargetApi(Build.VERSION_CODES.JELLY_BEAN)  
    private void openEnvelope(AccessibilityEvent event) {  
    	Log.w(TAG, "openEnvelope curWindow:" + event.getClassName());
    	
    	currentWindowName = (String)event.getClassName();
    	
        if ("com.tencent.mm.plugin.luckymoney.ui.LuckyMoneyReceiveUI".equals(event.getClassName())) {  
            //点中了红包，下一步就是去拆红包  
            checkKey1();  
        } else if ("com.tencent.mm.plugin.luckymoney.ui.LuckyMoneyDetailUI".equals(event.getClassName())) {  
            //拆完红包后看详细的纪录界面  
            //nonething  
        	this.showMoneyPack();
        } else if ("com.tencent.mm.ui.LauncherUI".equals(event.getClassName())) {  
            //在聊天界面,去点中红包  
            checkKey2();  
//            if(this.tryToSendMoneyPack){
//            	this.checkSelfPack();
//            }
        }
        else if(currentWindowName.equals(PAY_MONEY_PACK)){
        	Toast.makeText(this, "你确定要发红包呀？", Toast.LENGTH_SHORT).show();
        	this.tryToSendMoneyPack = true;
        }
    }  
    
    
    /**
     * 说出来
     * @param info
     */
    private void speack(String info){
    	Log.w(TAG, "speack :" + info);
    	if(!needSpeck)return;
    	if(hasLanguage && mTextToSpeech != null){
    		mTextToSpeech.speak(info, TextToSpeech.QUEUE_FLUSH, null);
    		Log.w(TAG, "speack successfull");
    	}
    	else
    	{
    		if(!hasLanguage){
    			Log.w(TAG, "no language");
    		}
    		
    		if(mTextToSpeech == null){
    			Log.w(TAG, "no mTextToSpeech");
    		}
    	}
    }
    
    private void showMoneyPack(){
    	
    	AccessibilityNodeInfo nodeinfo = this.getRootInActiveWindow();
    	if(nodeinfo != null){
    		String from = "";
    		List<AccessibilityNodeInfo> list = nodeinfo.findAccessibilityNodeInfosByText("元");
    		if(list.size() > 0){
    			AccessibilityNodeInfo parent = list.get(0).getParent();
    			if(parent != null){
    				AccessibilityNodeInfo moneyNode = parent.getChild(0);
    				if(moneyNode != null){
    					from =  "领取了" + moneyNode.getText();
    				}
    			}
    		}
    		
    		if(!from.equals("")){
    			List<AccessibilityNodeInfo> listMoney = nodeinfo.findAccessibilityNodeInfosByText(".");
    			String money = "";
    			if(listMoney.size() > 0){
    				try
    				{
    					money = (String) listMoney.get(0).getText();
    				}
    				catch(Exception e){
    				}
    				
    			}
    			
    			String ret = from;
    			if(!money.equals("")){
    				ret = from + money + "元";
    			}
    			
    			Toast.makeText(this, ret, Toast.LENGTH_SHORT).show();
    			this.speack(ret);
    			
    		}
    		
    	}
    }
    
 
    
    private void checkSelfPack(){
    	
    }
    
    
    private List<AccessibilityNodeInfo> getButton(AccessibilityNodeInfo node){
    	
    	List<AccessibilityNodeInfo> rect= new ArrayList<AccessibilityNodeInfo>();
    	
    	int childCount = node.getChildCount();
    	for (int i = 0; i < childCount; i++) {
			AccessibilityNodeInfo child = node.getChild(i);
			if(child.getChildCount() > 0){
				rect.addAll(getButton(child));
			}
			else
			{
				if(child.getClassName().equals("android.widget.Button")){
					rect.add(child);
				}
			}
			
		}
    	
    	return rect;
    }
  
    @TargetApi(Build.VERSION_CODES.JELLY_BEAN)  
    private void checkKey1() {  
        AccessibilityNodeInfo nodeInfo = getRootInActiveWindow();  
        if (nodeInfo == null) {  
            Log.w(TAG, "rootWindow为空");  
            return;  
        }         
        
        List<AccessibilityNodeInfo> list = nodeInfo.findAccessibilityNodeInfosByText(CHA_MONEY_PACK); 
        if(list.size() == 0){
        	list = this.getButton(nodeInfo);
        }
        
        for (AccessibilityNodeInfo n : list) {  
          n.performAction(AccessibilityNodeInfo.ACTION_CLICK);
        }  
        
    }  

    /**
     * 点开聊天里的红包
     */
    @TargetApi(Build.VERSION_CODES.JELLY_BEAN)
    private void checkKey2() {  
        AccessibilityNodeInfo nodeInfo = getRootInActiveWindow();  
        
       
        if (nodeInfo == null) {  
            Log.w(TAG, "checkKey2 rootWindow为空");  
            return;  
        }  
        List<AccessibilityNodeInfo> list = nodeInfo.findAccessibilityNodeInfosByText("领取红包");
        
        /**
         * 自己发的红包
         */
        if(list.isEmpty()){
        	list = nodeInfo.findAccessibilityNodeInfosByText("查看红包");
        }
        else
        {
        	for(AccessibilityNodeInfo self : nodeInfo.findAccessibilityNodeInfosByText("查看红包")){
            	if(tryToSendMoneyPack)
            		list.add(self);
            }
        }
        
        
        
        
        if (list.isEmpty()) {  
            list = nodeInfo.findAccessibilityNodeInfosByText(ENVELOPE_TEXT_KEY);  
            for (AccessibilityNodeInfo n : list) {  
            	
            	Log.i(TAG, "-->微信红包:" + n);  
                n.performAction(AccessibilityNodeInfo.ACTION_CLICK); 
                break; 
            }  
        } else {  
            //最新的红包领起  
            for (int i = list.size() - 1; i >= 0; i--) {  
                AccessibilityNodeInfo parent = list.get(i).getParent();  
              
                if(parent != null)
                {
                	Log.i(TAG, "-->领取红包:" + parent.hashCode() + "   " + parent); 
                    parent.performAction(AccessibilityNodeInfo.ACTION_CLICK); 
                    this.speack("红包来了");
                    break;
                }
                else
                {
                	Log.i(TAG, "-->红包不存在"); 
                }
                
                
            }  
        }
        
        
        
    }  
    
}  

