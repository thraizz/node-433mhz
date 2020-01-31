'use strict';

const express = require('express')
const app = express()
const port = 3000
const { exec } = require('child_process');

var lightswitchCounter = 0;
var lightswitchState = false;

app.get('/', function(req, res){
    var c = lightswitchState ? 1 : 2;

    // if(lightswitchState){
    //     var c = 1;
    // }
    // else{
    //     var c = 2;
    // }

    exec('./433mhz '+c, (error, stdout, stderr) => {
        if (error) {
          console.error(`Error: ${error}`);
          return;
        }
        else{
            lightswitchCounter++;
            lightswitchState =! lightswitchState;
        }
      })
    var s = lightswitchState ? "on" : "off";
    res.send('Lightswitch has been flipped '+lightswitchCounter+' times and the light is currently '+s+'!')
})
app.listen(port, () => console.log(`Example app listening on port ${port}!`))