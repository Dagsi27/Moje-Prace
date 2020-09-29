<template>
    <div class="content">
        <div>   
            <div class="user-list">
                <h2>{{user.name}}</h2>
                <p>User Name: {{user.username}}</p>
                <p>Phone Number: {{user.email}}</p>
                <p>Phone: {{user.phone}}</p>
                <p>website: {{user.website}}</p>

            </div>
        </div>
    </div>
</template>

<script>
export default {
    data(){
        return{
            id: this.$route.params.id,
            user:{}
        }
    },
    created() {
        this.$http.get('https://jsonplaceholder.typicode.com/users/'+this.id).then(function(data){
            this.user=data.body
        });
        console.log("done");
    }
}
</script>

<style scoped>
    .user-list{
        box-shadow: 2px 2px 13px 0px #525252;
        padding: 10px 30px 20px 30px;
        margin-bottom: 20px;
        background: white;
    }
</style>