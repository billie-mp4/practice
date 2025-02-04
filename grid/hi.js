const btn=document.createElement('button')
btn.textContent='change size'
document.body.appendChild(btn)
let container=document.createElement('div')
container.className='container'
const makeGrid=x=>{   
    container=document.createElement('div')
    container.className='container'
    for(i=0;i<x;i++){
        const row=document.createElement('div')
        row.className='row'
        for(j=0;j<x;j++){
            const block=document.createElement('div')
            block.className='block'
            row.appendChild(block)
        }
        container.appendChild(row)
    }
    document.body.appendChild(container)
}
makeGrid(4)
btn.addEventListener('click',e=>{
    const input=parseInt(prompt('num of squares per side'))/2
    if(input>100)return
    container.remove()
    makeGrid(input)
})