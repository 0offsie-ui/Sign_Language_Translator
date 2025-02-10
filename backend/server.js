const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const path = require('path');
const app = express();
const port = 3000;
const configPath = path.join(__dirname, 'config.json');

app.use(bodyParser.json());

// GET endpoint for configuration
app.get('/config', (req, res) => {
  fs.readFile(configPath, (err, data) => {
    if(err) return res.status(500).json({ error: 'Cannot read config file.' });
    res.json(JSON.parse(data));
  });
});

// POST endpoint to update configuration
app.post('/config', (req, res) => {
  fs.writeFile(configPath, JSON.stringify(req.body, null, 2), (err) => {
    if(err) return res.status(500).json({ error: 'Cannot write config file.' });
    res.json({ message: 'Config updated successfully.' });
  });
});

// New endpoint for translation
app.post('/translate', (req, res) => {
  const data = req.body;
  // Assume data contains: angle1, angle2, angle3, angle4, angle5, x, y
  let letter = '';
  let { angle1, angle2, angle3, angle4, angle5, x, y } = data;
  
  // Define sensor position flags
  const horizontal = (x >= 309 && x <= 390) && (y >= 270 && y <= 320);
  const vertical = (x >= 410 && x <= 462) && (y >= 310 && y <= 405);
  const equilibrium = (x >= 317 && x <= 385) && (y >= 315 && y <= 390);
  
  // Complete conditions from A to Z based on the .INO file
  if ((angle1 <= 40) && (angle2 >= 60) && (angle3 >= 72) && (angle4 >= 68) && (angle5 >= 72)) {
    letter = 'A';
  } else if ((angle1 >= 35) && (angle2 <= 15) && (angle3 <= 15) && (angle4 <= 15) && (angle5 <= 15)) {
    letter = 'B';
  } else if ((angle1 < 20) &&
             (angle2 >= 30 && angle2 < 80) &&
             (angle3 >= 30 && angle3 < 85) &&
             (angle4 >= 30 && angle4 < 85) &&
             (angle5 >= 30 && angle5 < 85)) {
    letter = 'C';
  } else if (((angle1 >= 30) && (angle1 <= 70)) &&
             (angle2 <= 15) &&
             (angle3 >= 60) &&
             (angle4 >= 40) &&
             (angle5 >= 40) &&
             vertical) {
    letter = 'D';
  } else if ((angle1 >= 85) && (angle2 >= 85) && (angle3 >= 85) && (angle4 >= 85) && (angle5 >= 85)) {
    letter = 'E';
  } else if ((angle1 >= 30) && (angle2 >= 40) && (angle3 <= 15) && (angle4 <= 15) && (angle5 <= 15)) {
    letter = 'F';
  } else if ((angle1 <= 30) &&
             (angle2 <= 15) &&
             (angle3 >= 55) &&
             (angle4 >= 55) &&
             (angle5 >= 60) &&
             horizontal) {
    letter = 'G';
  } else if ((angle1 >= 40) &&
             (angle2 <= 15) &&
             (angle3 <= 15) &&
             (angle4 >= 55) &&
             (angle5 >= 50) &&
             horizontal) {
    letter = 'H';
  } else if ((angle1 >= 30) &&
             (angle2 >= 70) &&
             (angle3 >= 55) &&
             (angle4 >= 55) &&
             (angle5 <= 30) &&
             vertical) {
    letter = 'I';
  } else if ((angle1 >= 30) &&
             (angle2 >= 70) &&
             (angle3 >= 55) &&
             (angle4 >= 55) &&
             (angle5 <= 30) &&
             !vertical) {
    letter = 'J';
  } else if ((angle1 <= 30) &&
             (angle2 <= 15) &&
             (angle3 <= 15) &&
             (angle4 >= 55) &&
             (angle5 >= 55) &&
             vertical) {
    letter = 'K';
  } else if ((angle1 <= 10) &&
             (angle2 <= 18) &&
             (angle3 >= 40) &&
             (angle4 >= 40) &&
             (angle5 >= 40) &&
             vertical) {
    letter = 'L';
  } else if (((angle1 >= 30) && (angle1 <= 75)) &&
             ((angle2 >= 40) && (angle2 < 80)) &&
             ((angle3 >= 40) && (angle3 < 80)) &&
             ((angle4 >= 50) && (angle4 <= 85)) &&
             (angle5 >= 85)) {
    letter = 'M';
  } else if (((angle1 >= 30) && (angle1 <= 70)) &&
             ((angle2 >= 40) && (angle2 < 80)) &&
             ((angle3 >= 40) && (angle3 < 80)) &&
             (angle4 > 85) &&
             (angle5 >= 85)) {
    letter = 'N';
  } else if ((angle1 >= 20) &&
             (angle2 >= 30 && angle2 < 80) &&
             (angle3 >= 30 && angle3 < 85) &&
             (angle4 >= 30 && angle4 < 85) &&
             (angle5 >= 30 && angle5 < 85) &&
             vertical) {
    letter = 'O';
  } else if ((angle1 <= 40) &&
             (angle2 <= 15) &&
             (angle3 <= 30) &&
             (angle4 >= 55) &&
             (angle5 >= 55) &&
             equilibrium) {
    letter = 'P';
  } else if ((angle1 <= 15) &&
             (angle2 <= 15) &&
             (angle3 >= 50) &&
             (angle4 >= 50) &&
             (angle5 >= 60) &&
             equilibrium) {
    letter = 'Q';
  } else if ((angle1 >= 30) &&
             (angle2 <= 10) &&
             ((angle3 >= 10) && (angle3 <= 20)) &&
             (angle4 >= 55) &&
             (angle5 >= 55) &&
             vertical) {
    letter = 'R';
  } else if (((angle1 >= 60) && (angle1 < 85)) &&
             (angle2 >= 70) &&
             (angle3 >= 70) &&
             (angle4 >= 70) &&
             (angle5 >= 70)) {
    letter = 'S';
  } else if (((angle1 >= 10) && (angle1 <= 40)) &&
             ((angle2 >= 20) && (angle2 <= 50)) &&
             (angle3 >= 80) &&
             (angle4 >= 80) &&
             (angle5 >= 80)) {
    letter = 'T';
  } else if ((angle1 >= 30) &&
             (angle2 <= 10) &&
             (angle3 < 10) &&
             (angle4 >= 55) &&
             (angle5 >= 55) &&
             vertical) {
    letter = 'U';
  } else if ((angle1 >= 30) &&
             (angle2 <= 10) &&
             (angle3 < 10) &&
             (angle4 >= 55) &&
             (angle5 >= 55) &&
             vertical) {
    letter = 'V';
  } else if ((angle1 >= 40) &&
             (angle2 <= 10) &&
             (angle3 <= 15) &&
             (angle4 <= 15) &&
             (angle5 >= 55)) {
    letter = 'W';
  } else if ((angle1 >= 30) &&
             ((angle2 >= 15) && (angle2 <= 40)) &&
             (angle3 >= 30) &&
             (angle4 >= 30) &&
             (angle5 >= 30) &&
             vertical) {
    letter = 'X';
  } else if ((angle1 <= 10) &&
             (angle2 >= 44) &&
             (angle3 >= 40) &&
             (angle4 >= 40) &&
             (angle5 <= 15)) {
    letter = 'Y';
  } else if (((angle1 >= 30) && (angle1 <= 70)) &&
             (angle2 <= 15) &&
             (angle3 >= 60) &&
             (angle4 >= 40) &&
             (angle5 >= 40) &&
             !vertical) {
    letter = 'Z';
  } else {
    letter = '?';
  }
  res.json({ letter });
});

app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});
