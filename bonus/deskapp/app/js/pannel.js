'use strict';

const ipc = require('ipc');
const remote = require('remote');
const path = require('path');
const fs = require('fs');
const childProcess = require('child_process');


function addInstance() {
  var playersPerTeam = document.getElementById('ppt').value.trim();
  var nbTeam = document.getElementById('nbTeam').value.trim();
  var path = childProcess.execSync('./app/randomfolder.sh', ['/bin']).toString().trim();
  if (parseInt(playersPerTeam) * parseInt(nbTeam) > 100000) {
    console.log("Too much players");
    return false;
  }
  childProcess.exec('./app/launch ' + [playersPerTeam, path, nbTeam, document.getElementById('globBaronne').value, document.getElementById('globMartinez').value, document.getElementById('globSam').value].join(' '), [], function(e, stdout, stderr) {
      console.log(stdout);
      console.log(stderr);
      console.log(e);
  });
}

function fclean() {
  childProcess.execSync('ipcrm -a');
  childProcess.execSync('killall lemipc');
}

childProcess.execSync('make re -C ../../', []);
childProcess.execSync('make re -C ../interface/', []);

fclean();
