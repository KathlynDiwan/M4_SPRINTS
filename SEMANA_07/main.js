const userChoiceDisplay = document.createElement('h1') //display da escolha dp usuário 
const computerChoiceDisplay = document.createElement('h1') //display da escolha do computador 
const resultDisplay = document.createElement('h1') 
const game = document.getElementById('game')
game.append(userChoiceDisplay, computerChoiceDisplay, resultDisplay)

const choices = ['Pedra', 'Papel', 'Tesoura'] //opções 
let userChoice //escolha do usuário 
let computerChoice //escolha do computador 

const handleClick = (e) => {
  userChoice = e.target.id 
  userChoiceDisplay.innerHTML = 'Sua Escolha: ' + userChoice
  generateComputerChoice() 
  getResult()
}

const generateComputerChoice = () => { //a escolha do computador será gerada aleatoriamente 
  const randomChoice = choices[Math.floor(Math.random() * choices.length)] //Math.random - comando 
  computerChoice = randomChoice //algoritmo que identifica que a randomChoice será o  computerChoice
  computerChoiceDisplay.innerHTML = 'Oponente IA: ' + computerChoice
}

for (let i = 0; i < choices.length; i++) {
  const button = document.createElement('button')
  button.id = choices[i] 
  button.innerHTML = choices[i]
  button.addEventListener('click', handleClick)
  game.appendChild(button)
}

const getResult = () => { //criando situações diversas 

  //situação em que o usuário vence 
  switch (userChoice + computerChoice) {
    case 'TesouraPapel': //tesoura > papel - vencedor 
    case 'PedraTesoura': //pedra > tesoura - vencedor
    case 'PapelPedra': //papel > pedra - vencedor
      resultDisplay.innerHTML = "VOCÊ VENCEU!"

    //situação em que o usuário perde
      break
    case 'PapelTesoura': //papel < tesoura - perdedor
    case 'TesouraPedra': //tesoura < pedra - perdedor 
    case 'PedraPapel': // pedra < papel - perdedor
      resultDisplay.innerHTML = "VOCÊ PERDEU!"

    //situação em que o usuário empata com o computador 
      break
    case 'PapelPapel': // papel = papel 
    case 'TesouraTesoura': // tesoura = tesoura 
    case 'PedraPedra': //pedra =
    resultDisplay.innerHTML = "EMPATE!"
    break
  }
}