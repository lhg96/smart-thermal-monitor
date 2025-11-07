package com;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.ws.rs.Consumes;
import javax.ws.rs.DELETE;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.core.MediaType;

import org.json.JSONObject;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

@Path("/thermal")
public class ThermalAPI extends HttpServlet {	
	private static final long serialVersionUID = 1L;
	Gson gson;
	
	@Override
	public void init() throws ServletException {		
		super.init();
		System.out.println("---------init APT servlet-----------------");
		gson 	= new GsonBuilder().setPrettyPrinting().create();		
					
	}	
	
	@GET
	@Consumes(MediaType.APPLICATION_JSON)
	@Path("/last")
	public String getEnvTemp(){
		String returnValue = "";
		String address= "http://api.thingspark.kr/channels/65703/last";
		try {
			URL url = new URL(address);
			BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
			StringBuffer json = new StringBuffer();
			String line;
			while ((line = reader.readLine()) != null) {
			  json.append(line);
			}			
			JSONObject obj = new JSONObject(json.toString());
			
			String field1 = obj.get("field1").toString();
			String field2 = obj.get("field2").toString();
			String field3 = obj.get("field3").toString();
			String regDate = obj.get("created_at").toString();
			
			returnValue = field1+"/"+field2+"/"+field3+"/"+regDate;
			reader.close();		
			
		} catch (IOException e) {			
			e.printStackTrace();
		}	
		return returnValue;
		/*
		int len = 10; //default	
		String address = "https://api.thingspark.kr/channels/65703/entrys?results="+len;
		
		List<Thermal> thermalList = new ArrayList();
		try {
			URL url = new URL(address);
			BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
			StringBuffer json = new StringBuffer();
			String line;

			while ((line = reader.readLine()) != null) {
			  json.append(line);
			}
			System.out.println(json);
			reader.close();		
			
					
			JSONObject obj = new JSONObject(json);
			//JSONArray arr = obj.getJSONArray("entrys");			
			//System.out.println(arr);			
			
			
			JSONObject entryObj = obj.getJSONObject("entrys");
			System.out.println(entryObj);*/
			/*
			for(int i = 0;i<arr.length();i++) {
				String envTempS  =  arr.getJSONObject(i).getString("field1");
				String objTempS  =  arr.getJSONObject(i).getString("field2");
				String distanceS =  arr.getJSONObject(i).getString("field3");
				String regDateS  =  arr.getJSONObject(i).getString("created_at");			
				//System.out.println(envTemp+"/"+objTemp+"/"+distance+"/"+regDate);
				
				double envTemp = convertDouble(envTempS);
				double objTemp = convertDouble(objTempS);
				double distance = convertDouble(distanceS);
				Date   regDate = convertDate(regDateS);
				
				Thermal thermal = new Thermal(envTemp, objTemp, distance, regDate);
				System.out.println(thermal);
				thermalList.add(thermal);
			}
			*/
			/*
			response.setContentType("application/json");
			response.setCharacterEncoding("UTF-8");
			//response.getWriter().println(gson.toJson(thermalList));	
			
		} catch (IOException e) {			
			e.printStackTrace();
		}*/
	}	
	
	
	private double convertDouble(String inStr) {
		double value = -1;
		if (inStr != null && inStr.trim().length() > 0) {
			try {
				value = Double.parseDouble(inStr);
			} catch (NumberFormatException e) {
				//logger.error(e.toString());
				
			}
		}
		return value;
	}
	



	private Date convertDate(String dataTimeStr) {
		//String dateFormat = "yyyy-MM-dd HH:mm";
		dataTimeStr = dataTimeStr.replace("T", " ");
		String dateFormat ="yyyy-MM-dd HH:mm:ss.SSSZ";
						 //"2020-09-05T10:05:49.000+0000";
		SimpleDateFormat simpleDateFormat = new SimpleDateFormat(dateFormat);
		Date date = null;
		try {
			date = simpleDateFormat.parse(dataTimeStr);
		} catch (ParseException e) {			
			//logger.error(e.toString());
		}
		return date;
	}
	
}

class Last{
	String field1;
	String field2;
	String field3;
	String created_at;
	public String getField1() {
		return field1;
	}
	public void setField1(String field1) {
		this.field1 = field1;
	}
	public String getField2() {
		return field2;
	}
	public void setField2(String field2) {
		this.field2 = field2;
	}
	public String getField3() {
		return field3;
	}
	public void setField3(String field3) {
		this.field3 = field3;
	}
	public String getCreated_at() {
		return created_at;
	}
	public void setCreated_at(String created_at) {
		this.created_at = created_at;
	}
	public Last(String field1, String field2, String field3, String created_at) {
		super();
		this.field1 = field1;
		this.field2 = field2;
		this.field3 = field3;
		this.created_at = created_at;
	}
	@Override
	public String toString() {
		return "Last [field1=" + field1 + ", field2=" + field2 + ", field3=" + field3 + ", created_at=" + created_at
				+ "]";
	}
}


class Thermal{
	double  envTemp;
	double  objTemp;
	double  distance;
	Date regDate;
	
	
	public Thermal(double envTemp, double objTemp, double distance, Date regDate) {
		super();
		this.envTemp = envTemp;
		this.objTemp = objTemp;
		this.distance = distance;
		this.regDate = regDate;
	}
	
	public double getEnvTemp() {
		return envTemp;
	}
	public void setEnvTemp(double envTemp) {
		this.envTemp = envTemp;
	}
	public double getObjTemp() {
		return objTemp;
	}
	public void setObjTemp(double objTemp) {
		this.objTemp = objTemp;
	}
	public double getDistance() {
		return distance;
	}
	public void setDistance(double distance) {
		this.distance = distance;
	}
	public Date getRegDate() {
		return regDate;
	}
	public void setRegDate(Date regDate) {
		this.regDate = regDate;
	}
	@Override
	public String toString() {
		return "Thermal [envTemp=" + envTemp + ", objTemp=" + objTemp + ", distance=" + distance + ", regDate="
				+ regDate + "]";
	}
}