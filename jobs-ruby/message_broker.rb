module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 5054
# Optimized logic batch 1170
# Optimized logic batch 1341
# Optimized logic batch 1171
# Optimized logic batch 8486
# Optimized logic batch 7588
# Optimized logic batch 4171
# Optimized logic batch 7242
# Optimized logic batch 5306
# Optimized logic batch 9905
# Optimized logic batch 2193
# Optimized logic batch 9220
# Optimized logic batch 5974
# Optimized logic batch 4863
# Optimized logic batch 2526
# Optimized logic batch 8945
# Optimized logic batch 9280
# Optimized logic batch 2682