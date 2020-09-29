<template>
    <div class="content">
        <div>
            <div class="search-user">
                <input v-model="search" type="text" placeholder="Find User"/>
            </div>
                
            <div class="user-list" v-for="user in filteredUser" v-bind:key="user.id">
                <h2><router-link :to="`/users/${user.id}`">{{user.name}}</router-link></h2>
                <p>User Name: {{user.username}}</p>
                <p>Street: {{user.address.street}}</p>
                <p>City: {{user.address.city}}</p>
                <p>Phone Number: {{user.phone}}</p>
            </div>
        </div>
    </div>
</template>

<script>
export default {
    data(){
        return{
            users:[],
            search:''
        }
    },
    created() {
        this.$http.get('https://jsonplaceholder.typicode.com/users').then(function(data){
            this.users=data.body
        });
        console.log("done");
    },
    computed:{
        filteredUser(){
            return this.users.filter((user)=>{
                return user.name.match(this.search);
            });
        }
    }
}
</script>

<style scoped>
    .search-user{
        box-shadow: 2px 2px 13px 0px #525252;
        padding: 20px 30px 20px 30px;
        margin-bottom: 20px;
        background: white;
    }

    .search-user input{
        padding: 10px;
        font-size: 18px;
        border: 1px solid grey;
        display: block;
        margin:auto;
        width: 90%;
        background: #f1f1f1;
    }

    .user-list{
        box-shadow: 2px 2px 13px 0px #525252;
        padding: 10px 4% 20px 4%;
        margin-bottom: 20px;
        width:40%;
        display:inline-block;
        background: white;
    }

    .user-list:nth-child(2n+1){
        float:right;
    }

    a{
        white-space:nowrap;
        width:0px;
        color:#111111;
        text-decoration: none;
        display: block;
        transition: .5s;
    }
</style>