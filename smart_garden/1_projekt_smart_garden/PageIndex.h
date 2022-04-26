// HTML DIO ZA STRANICU

const char MAIN_page[] PROGMEM = R"=====(
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }
      h1 { font-size: 2.0rem; }
      p { font-size: 2.0rem; }
      .units { font-size: 1.2rem; }
      .dht-labels{
        font-size: 1.5rem;
        vertical-align:middle;
        padding-bottom: 10px;
      }
    </style>
  </head>
  <body>
    <h1>NodeMCU ESP8266 smart garden</h1>

    
    <p>
    <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEAAAABACAYAAACqaXHeAAAACXBIWXMAAAsTAAALEwEAmpwYAAAHSUlEQVR4nO2bf4xcVRXHP+fNbn9sf4MlbVdjSRQwC62hSlMVFIMIbQp0d9+b3ZWixmRr+VGMCo006BpNRfwRi0FaSwKhaXfnzXZpXWQTQDQpxTShNGgDxRDxD9ptq7WtsN3u7sw7/tHd6b4fs9u5b96IWb5/zT333O8598y9971737lCBaHdK2s4W5NGdRWwFJgLDIK+hUgPeWmXpsyrlfRJKmVIXXs1yEPAgnFUd4LeK072cCX8SjwA6topRDah3FVCs6NY1m3S2LEvMceGYSVtAKyHS+w8wDw8r0c7Gz6eiEujkOgI0Gz6VlR3xaB4DXSJONl82ZwKILERoFtaq1H9eUyaxah8tSwOFUFyU+Ci09cDH4uu1OcQuQv0C6D1KD8GjkWqCmuScvEcfULQjPMowp0B8WlQW5zs8yH9p1ZPY+pAG8p3Q2R5q1aaO44k4WdyI0D08oAkh1gNUZ0HkDu29dHo3g+yKVSZyie2GCb5FJjnKykZsTv+MFYDEZSTs+4DjvorrPll924YCQZAqvyW5JULarXmt0OgB3xCT6uKqMdGBd4DhqFergTt/sT8CKByASgJ1lDFLFXKUEkQneAB8JjgARCZ4AFQLWXBjIXEHi/FoK69FuQnEVV94ri1wPAI0Ir4U/EAINZkVGeN6YvoUIX6/z6dAh8sghN9EfzgPWDCT4GJPgJUKvYe8P4MwIQfATLRd4PehB8B/+cB0O6VNcB0Y4LgFBBtUdeeG9OtSJQ9AOran6S/Zj9Qa0wSmgJyM8hBde0vxfMujLIGQDPOcpCXQa+IRWRFPgYvAXlWM87tsbiDpspFpNl0PcJuYGp8Mu9MkZoqhG3q2i2xbQyjLAFQ174G1e1Eb689hM3kqjoulE+c7IugNwJ/LaLxhGaczxo5G0DsAOj2ljkgTwNTIqqPgH5ebHettLT/qxRecbLPM/3dT6P8OqJ6EkK7unbUuUJJiD8CqvM/Izrr4zCp3FJxsi/5xTqpmC+6pbV6tECW9wxI2l0Hen+E/kfA+oWJyz4bcRqray+ByC8+fVjWtdLYcWCU7kWoPIhwN8VPov6ByENM+8+TsrxnwGcr42xE+F6EF4vEyRaZKuMj5giQDRFCRWn2dT7jfBnkLYRvMfYx3EJUN/PezDe1s7nOV3PJ8e+D7onw4UEz34dbmzbU9qaFpLy3Ixi3iu22FvRc+4sgvyd6jRgLJ7Csm6SxozDCtCN9JZa+hv+P80BrxckeDVOMD/MRYHmNEdIBrNwPRgra2bwIpJvSOw9wMZ73ou6s/+iIQJoyBxF2BD1BLNuAf7ixKYTbImRd0tDVWyh7+Y1AjbENmEG++kc+icfWkJbqLaYGjAKgrp0Crg7XyI5ROsuAFaaOjbJ2u3akFxeKjruHYP4AfErVbDqbjQDPuoyoN77B1N5R1PcacYchWNxTKAgK7A3ozKar4VITcrMAiEZsdOTv8pUdJ8+X9Voj7kjo5/xFDoZVqo12i2YBsGROWKiFLC917UmMnxJbCoL/7r9DGnlvtgmx6SKYCou0cocrUQcmlhh9TDNzWr3esNAqJEWJkx0EThhxRyOQImfNC2mI/NOE2HAKeBE5ezo/sBIfMuKOhp9LNJw1NkRJm60RmAXgTE1U0uIkMulFhZLSbcQdBRE/l3JNSCeVr1wA5I5tfaB/CbN5txZ+V+W2A2dN+AN4lyHLHSloe9NCYLFfRV8RJ2uUWWa+cKn8LkLqaFubBSANXe+A/MqY/7yhn/rOEqo8J6Qi8owpe5kDIHXUvXHewb6pPwT+bGwDXuDknIcLJl17Fkr4bED1fxCAQ5/YD7wZ4cxGfeJrUwDk60+eJZdaBewv3YDuoXrQPpc5OiKS9cDFAcU3eL3uAIYwDoC0tXmIPBBRdSnTz2wdeSJIS/sxpvZfh/I4F5b4kx9OmL5BVu06NSJU174JYX1IW3lA2to8w27EPBFShKyzF1gW4dgGSbsbfSLXvgqRe1BWEkymhsMou1HZJE2Zv/nadTbX4eVfBmYGjOzDzi4b3h8YIfZ9Ae1sWornvUTUSY/wCB86/h25/k++c35ta7O4/NA8qllATj2qh3qp7zoa1RHNpm9E1QWCB6A50OvEycZZY8pzYUKz6TWobi5S/Uc8WSdNmfAGZizO3bfMYHDKfSgbiJqqIt8UO7PFwF0/TVyCEaib/g3o2mLVKNsQ3czrdfvGmrO6s/7DeFVplPWcu1gZAXlMnEzwNooRyheALa3VzDn9GOg3xlE9BvIc8DbCEaAfT+cDtQifAZaMbYjHOTX7Tt/TIQbKemfo3KJorwP5JeX/8OqBfhs7+0icRS+IRC5Naca5AeFR4LLyMMohRO4e78qNCRLZw0vafYGTs69EWQscj0HVi9LK3GNXJdF5qMTd4adWT2PywApgFcIKYMY4TU4hPIPHLmr6e2Rld7EvxWVBxW6PA+izN0/mvelXA7WoLMBiAR4eokdQ6SVlvcOJma+Wa4G7EPwX2VVmbnBoC34AAAAASUVORK5CYII=" align="middle" style="padding-bottom: 20px;">
      <span class="dht-labels">Temperatura zraka: </span> 
      <span id="TemperatureValue" style="color:#ffaa56;">0</span>
      <sup class="units">&deg;C</sup>
      
      <span class="dht-labels">Temperatura zemlje: </span> 
      <span id="GroundTempValue" style="color:#ffaa56;">0</span>
      <sup class="units">&deg;C</sup>
    </p>

    
    <p>
    <img src="data:image/png;base64,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" align="middle" style="padding-bottom: 20px;">
      <span class="dht-labels">Vlaga zraka: </span>
      <span id="HumidityValue" style="color:#4da5fc;">0</span>
      <sup class="units">%</sup>

      <span class="dht-labels">Vlaga zemlje: </span> 
      <span id="readHumidityGround" style="color:#4da5fc;">0</span>
      <sup class="units">%</sup>
    </p>


    
    <p>
    <img src="data:image/png;base64,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" width="20" height="20" align="middle" style="padding-bottom: 12px;">
      <span style="font-size:1.0rem;">Time </span>
      <span id="time" style="font-size:1.0rem;"></span>
    
    <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEAAAABACAYAAACqaXHeAAAACXBIWXMAAAsTAAALEwEAmpwYAAAA1ElEQVR4nO3bwQqCQBgA4TZ6Rh/Sl6y7QiIlX+nMUXEZhnUPPzpuGzyn+fnu/pinsbXGkXzqd/+uzv9RAC2gGVvv0Nm5/A4ogBbQFEALaAqgBTQF0AKaAmgBTQG0gKYAWkDzWF7QM76jWc4/Lr8DCqAFNKszYIu9M8TlmaKfX3L5HVAALaApgBbQFEALaAqgBTQF0AKa1fcBzQMuRgG0gKZ5wJ7FzkgBtICmAFpAUwAtoCmAFtAUQAtomgcokV+hAFpAUwAtoCmAFtD036AW0BRAC2heXrU4ekB4r6wAAAAASUVORK5CYII=" width="20" height="20" align="middle" style="padding-bottom: 12px;">
      <span style="font-size:1.0rem;">Date </span>
      <span id="date" style="font-size:1.0rem;"></span>
    </P>

    
  <p>
    <span style="font-size:1.0rem;">Izradio Marko, Kopilica _2020._</span>
  </P>


    <script>
      setInterval(function() {
        // Call a function repetatively with 2 Second interval
        getTemperatureData();
        getHumidityData();
        getGroundTempData();
        getGroundHumidData();
      }, 2000); 
      
      setInterval(function() {
        // Call a function repetatively with 1 Second interval
        Time_Date();
      }, 1000); 




      function getTemperatureData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("TemperatureValue").innerHTML =
            this.responseText;
          }
        };
        xhttp.open("GET", "readTemperature", true);
        xhttp.send();
      }


      function getHumidityData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
          document.getElementById("HumidityValue").innerHTML =
          this.responseText;
          }
        };
        xhttp.open("GET", "readHumidity", true);
        xhttp.send();
      }





       function getGroundTempData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
          document.getElementById("GroundTempValue").innerHTML =
          this.responseText;
          }
        };
        xhttp.open("GET", "readTemperatureGround", true);
        xhttp.send();
      }


       function getGroundHumidData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
          document.getElementById("GroundHumidityValue").innerHTML =
          this.responseText;
          }
        };
        xhttp.open("GET", "readHumidityGround", true);
        xhttp.send();
      }





      
      function Time_Date() {
        var t = new Date();
        document.getElementById("time").innerHTML = t.toLocaleTimeString();
        var d = new Date();
        const dayNames = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"];
        const monthNames = ["January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"];
        document.getElementById("date").innerHTML = dayNames[d.getDay()] + ", " + d.getDate() + "-" + monthNames[d.getMonth()] + "-" + d.getFullYear();
      }
    </script>
  </body>
</html>
)=====";
