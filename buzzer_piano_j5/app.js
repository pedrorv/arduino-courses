const j5 = require('johnny-five')
const express = require('express')
const app = express()
const server = require('http').createServer(app)
const io = require('socket.io')(server)
const path = require('path')

app.use(express.static(path.join(__dirname, 'public')))
app.get('/', (req, res, next) => {
  res.sendFile(path.join(__dirname, 'index.html'))
})

const tones = {
  "A": true,
  "B": true,
  "C": true,
  "D": true,
  "E": true,
  "F": true,
  "G": true,
}

j5.Board().on('ready', () => {
  console.log('Arduino is ready')

  const Buzzer = new j5.Piezo(8)

  io.on('connection', (client) => {
    client.on('note', (data) => {
      if (tones[data]) {
        Buzzer.tone(j5.Piezo.Notes[data.toLowerCase() + 4], 50)
      }

      client.emit('note', data)
      client.broadcast.emit('note', data)  
    })
  })
})

const port = process.env.PORT || 8080

server.listen(port)
console.log(`Server listening on http://localhost:${port}`)
