'use strict';

const app = require('app');
const BrowserWindow = require('browser-window');
const childProcess = require('child_process');
const ipc = require('ipc');

var mainWindow = null;
var settingsWindow = null;

app.on('ready', function() {

    mainWindow = new BrowserWindow({
        resizable: true,
        width: 800,
        height: 400,
        useContentSize: true,// either `true` or `false`
        webPreferences: {
          offscreen: true
        }
    });

    mainWindow.loadUrl('file://' + __dirname + '/app/pannel.html');
});

app.on('close', function () {
  app.quit();
});
