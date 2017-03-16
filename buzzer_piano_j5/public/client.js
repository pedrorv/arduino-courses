(function() {
  var socket = io.connect(window.location.hostname + ':' + 8080)
  
  window.addEventListener('keydown', function(e) {
    socket.emit('note', e.key.toUpperCase())
  })
}())