const char MAIN_page[] PROGMEM = R"=====(
  <html lang='en'><head><meta name='viewport' content='width=device-width, initial-scale=1, user-scalable='no'/>
  <title>Controle Remoto</title>
  <style>.c{text-align: center;} div,input{padding:5px;font-size:1em;} input{width:70%;} body{background-color: #1fa3ec;color:#fff;text-align: center;font-family:verdana;margin: auto;width: 80%;} button{border:0;border-radius:0rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.5rem;width:5rem; height:3rem} .q{float: right;width: 64px;text-align: right;}button:hover{background-color:#1577ad;}ul {list-style-type: none; margin: 0; padding: 0; width: 100%; float:left; } li{float: left;} .h li { display: inline; float: left; } .b{background-color:white;} </style>
  <script>function startVibrate(){navigator.vibrate(50);}</script>
  </head>
  <a href='/' style='color:#fff;text-decoration: none;'><button<h3>Controle Remoto</h3></a>
  <ul><li><a href='\?function=p+'><button onClick='startVibrate()'>P +</button></a></li>
  <li><a href='\?function=cima'><button onClick='startVibrate()'>/\</button></a></li>
  <li><a href='\?function=mute'><button onClick='startVibrate()'>MUTE</button></a></li>
  <ul class='h'>
  <li><a href='\?function=vol-'><button onClick='startVibrate()'>Vol -</button></a></li>
  <li><a href='\?function=ok'><button onClick='startVibrate()'>OK</button></a></li>
  <li><a href='\?function=vol+'><button onClick='startVibrate()'>Vol +</button></a></li>
  </ul>
  <li><a href='\?function=p-'><button onClick='startVibrate()'>P -</button></a></li>
  <li><a href='\?function=baixo'><button onClick='startVibrate()'>\/</button></a></li>
  <li><a href='\?function=menu'><button onClick='startVibrate()'>MENU</button></a></li>
  </ul><ul class='h'>
  <li><a href='\?function=n1'><button onClick='startVibrate()'>1</button></a></li>
  <li><a href='\?function=n2'><button onClick='startVibrate()'>2</button></a></li>
  <li><a href='\?function=n3'><button onClick='startVibrate()'>3</button></a></li>
  </ul><ul class='h'>
  <li><a href='\?function=n4'><button onClick='startVibrate()'>4</button></a></li>
  <li><a href='\?function=n5'><button onClick='startVibrate()'>5</button></a></li>
  <li><a href='\?function=n6'><button onClick='startVibrate()'>6</button></a></li>
  </ul><ul class='h'>
  <li><a href='\?function=n7'><button onClick='startVibrate()'>7</button></a></li>
  <li><a href='\?function=n8'><button onClick='startVibrate()'>8</button></a></li>
  <li><a href='\?function=n9'><button onClick='startVibrate()'>9</button></a></li>
  </ul><ul class='h'>
  <li><a href='\?function=epg'><button onClick='startVibrate()'>EPG</button></a></li>
  <li><a href='\?function=n0'><button onClick='startVibrate()'>0</button></a></li> 
  <li><a href='\?function=inf'><button onClick='startVibrate()'>INFO</button></a></li></ul>
  <ul class='h'>
  <li><a href='\?function=audio'><button onClick='startVibrate()'>AUDIO</button></a></li>
  <li><a href='\?function=sair'><button onClick='startVibrate()'>SAIR</button></a></li>
  <li><a href='\?function=ON'><button onClick='startVibrate()'>ON/OFF</button></a></li>
  </ul>
  </html>
)=====";
