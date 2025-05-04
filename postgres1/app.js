import express from 'express'
import {Client} from 'pg'
import dotenv from 'dotenv'
dotenv.config()
const app=express()
async function main(SQL){
    const client=new Client({
        connectionString:process.env.URL,
    })
    await client.connect()
    const result=await client.query(SQL)
    await client.end()
    return result.rows
}
app.set('view engine','ejs')
app.use(express.urlencoded({extended:true}))
app.get('/delete',async function(req,res){
    await main('DELETE FROM usernames')
    res.send('deleted')
})
app.get('/',async function(req,res){
    const {search}=req.query
    const usernames=await main(`SELECT * FROM usernames WHERE username LIKE '%${search}%'`)
    res.render('searchResult',{usernames})
})
app.listen(process.env.PORT)