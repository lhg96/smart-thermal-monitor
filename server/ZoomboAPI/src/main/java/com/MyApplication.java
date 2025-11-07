package com;

import javax.ws.rs.ApplicationPath;

import org.glassfish.jersey.server.ResourceConfig;


/**
 * sample
 * https://www.codejava.net/java-ee/web-services/java-crud-restful-web-services-examples-with-jersey-and-tomcat
 * 
 * 
 * authorized
 * https://github.com/rohdef/jersey-auth-tutorial
 * 나중에 보안 참조할것
 * https://tutorial-academy.com/rest-jersey2-json-jwt-authentication-authorization/
 * 
 * 추후 업데이트 할 버젼
 * https://www.slideshare.net/turbomanage/easy-rest-ap-is-with-jersey-and-resty-gwt
 * 
 * 
 * datastore sort 기능
 * https://happycoding.io/tutorials/google-cloud/datastore
 * 
 * @author user
 *
 */
@ApplicationPath("api")
public class MyApplication extends ResourceConfig {

    public MyApplication() {
        packages("com.appspot.jerseyongae.api");
    }
}
