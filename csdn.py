import org.apache.commons.httpclient.*;  
import org.apache.commons.httpclient.methods.GetMethod;  
import org.apache.commons.httpclient.params.HttpMethodParams;  
  
public class Csdn {  
  
    @SuppressWarnings("deprecation")  
    public static void main(String[] args) {  
        HttpClient httpClient = new HttpClient();  
        GetMethod getMethod = new GetMethod("http://hi.csdn.net/gxiangzi");  
        getMethod.getParams().setParameter(HttpMethodParams.RETRY_HANDLER, new DefaultMethodRetryHandler());  
        for (int i = 1; i <= 25; i++) {  
            try {  
                int statusCode = httpClient.executeMethod(getMethod);  
                if (statusCode != HttpStatus.SC_OK) {  
                    System.out.print("失败：" + getMethod.getStatusLine());  
                }  
            // byte[] responseBody=getMethod.getResponseBody();获取网页内容  
            // System.out.print(new String(responseBody));  
            } catch (Exception e) {  
                System.out.print("请检查网络地址！");  
            } finally {  
                getMethod.releaseConnection();  
            }  
            System.out.println("您已经成功刷新了"+i+"次！");  
        }  
    }  
} 
